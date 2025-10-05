#include <unistd.h>
#include <stdint.h>

/*
ioctl(fd, uint32_t, uint64_t)
RCX: uint32_t
RDX:    uint64_t
RSI: uint32_t
R08:    uint64_t
R12: uint32_t
R14:    uint64_t
*/

struct tty_struct
{
    uint32_t magic;
    uint32_t kref;
    uint64_t *dev;
    uint64_t *driver;
    uint64_t *ops;
};

struct tty_struct fake_tty = {
    .magic = 0x5401,
    .kref = 0x10000,
    .dev = NULL,
    .driver = NULL,
    .ops = NULL};

struct fake_operations_table
{
    uint64_t lookup;
    uint64_t install;
    uint64_t remove;
    uint64_t open;
    uint64_t close;
    uint64_t shutdown;
    uint64_t cleanup;
    uint64_t write;
    uint64_t put_char;
    uint64_t flush_chars;
    uint64_t write_room;
    uint64_t chars_in_buffer;
    uint64_t ioctl;
    uint64_t compat_ioctl;
    uint64_t set_termios;
    uint64_t throttle;
    uint64_t stop;
    uint64_t start;
    uint64_t hangup;
    uint64_t break_ctl;
    uint64_t flush_buffer;
    uint64_t set_ldisc;
    uint64_t wait_until_sent;
    uint64_t send_xchar;
    uint64_t tiocmget;
    uint64_t resize;
    uint64_t set_termiox;
    uint64_t get_icount;
    uint64_t show_fdinfo;
};
