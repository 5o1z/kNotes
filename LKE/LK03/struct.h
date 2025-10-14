#include <stddef.h>

#define CMD_GET 0xdec50001
#define CMD_SET 0xdec50002

typedef struct
{
    char *ptr;
    size_t len;
} request_t;
