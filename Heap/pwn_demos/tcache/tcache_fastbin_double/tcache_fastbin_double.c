#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    void *chunks[8];

    for (int i = 0; i < 7; i++)
    {
        chunks[i] = malloc(0x10);
    }

    chunks[7] = malloc(0x10);

    for (int i = 0; i < 7; i++)
    {
        free(chunks[i]);
    }

    free(chunks[7]); // free normally to fastbin
    malloc(0x10); // take from tcache so that we have 1 free space in tcache
    /* VULN HERE */
    free(chunks[7]); // this time chunk is freed again to tcache
    /* VULN HERE */

    // now chunks[7] is in both tcache and fastbin
    // with this, on the next malloc(0x10), it will be taken from tcache
    // this time we can control the fd pointer of the fastbin chunk

    return 0;
}
