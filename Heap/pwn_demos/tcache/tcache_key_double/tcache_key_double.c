#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    long *chunk1, *chunk2, *duplicate;

    chunk1 = malloc(0x10);
    free(chunk1); // free normally to tcache

    /* VULN HERE */
    chunk1[1] = 0x0;   // nullify the key to bypass double free check
    free(chunk1);      // double free to tcache
    /* VULN HERE */

    chunk2 = malloc(0x10); // take the first chunk from tcache
    duplicate = malloc(0x10); // take the second chunk from tcache, which is the duplicate

    assert(chunk1 == duplicate); // both pointers should be the same

    return 0;
}
