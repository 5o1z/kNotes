#include <stdint.h>
#include <stddef.h>

typedef struct
{
    char *key;
    char *data;
    size_t keylen;
    size_t datalen;
} XorCipher;

typedef struct
{
    char *ptr;
    size_t len;
} request_t;
