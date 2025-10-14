#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long *tcache_chunks[7];
    long *fastbin_chunk0, *fastbin_chunk1, *fastbin_chunk2, *reallocated_chunk0, *reallocated_chunk1, *reallocated_chunk2;

    // Fill tcache for size 0x70
    for (int i = 0; i < 7; i++) {
        tcache_chunks[i] = malloc(0x70);
    }

    fastbin_chunk0 = malloc(0x70);
    fastbin_chunk1 = malloc(0x70);
    fastbin_chunk2 = malloc(0x70);

    malloc(0x70); // Prevent consolidation with top chunk

    for (int i = 0; i < 7; i++) {
        free(tcache_chunks[i]);
    }

    free(fastbin_chunk0);
    free(fastbin_chunk1);
    /* VULN HERE */
    free(fastbin_chunk0); // Double free vulnerability
    /* VULN HERE */

    for (int i = 0; i < 7; i++) {
        tcache_chunks[i] = malloc(0x70); // Empty tcache
    }

    reallocated_chunk0 = malloc(0x70);
    reallocated_chunk1 = malloc(0x70);
    reallocated_chunk2 = malloc(0x70);

    assert(reallocated_chunk0 == reallocated_chunk2); // Should be equal due to double free
    return 0;
}
