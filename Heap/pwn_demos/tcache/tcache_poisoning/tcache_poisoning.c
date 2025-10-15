#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long x[0x10], *target, *a, *b, *c;

    for (int i = 0; i < 0x10; i++) {
        if ((((long)&x[i]) & 0xF) == 0)
        {
            target = &x[i];
            break;
        }
    }

    a = malloc(0x80);
    b = malloc(0x80);

    free(a);
    free(b);

    /* VULN HERE */
    b[0] = (long)target ^ ((long)b >> 12); // ptr mangling
    /* VULN HERE */

    malloc(0x80);
    c = malloc(0x80);

    assert(c == target);
}
