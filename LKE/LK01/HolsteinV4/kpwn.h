#ifndef KPWN_H
#define KPWN_H

#define _GNU_SOURCE
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <liburing.h>
#include <pthread.h>
#include <sched.h>

#include <sys/ioctl.h>
#include <sys/capability.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/xattr.h>

#include <linux/capability.h>
#include <linux/types.h>

#define DEBUG
#define KADDR(addr) ((size_t)(addr) - 0xffffffff81000000 + kernel_base)

#ifdef DEBUG
#define errExit(msg)        \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

#define WAIT()                \
    do                        \
    {                         \
        puts("[WAITING...]"); \
        getchar();            \
    } while (0)

#define logOK(msg, ...) dprintf(2, "[+] " msg "\n", ##__VA_ARGS__);
#define logInfo(msg, ...) dprintf(2, "[*] " msg "\n", ##__VA_ARGS__);
#define logErr(msg, ...) dprintf(2, "[!] " msg "\n", ##__VA_ARGS__);
#else
#define errExit(...) \
    do               \
    {                \
    } while (0)

#define WAIT(...) errExit(...)
#define logOK(...) errExit(...)
#define logInfo(...) errExit(...)
#define logErr(...) errExit(...)
#endif

uint64_t user_rip;
uint64_t user_cs;
uint64_t user_rflags;
uint64_t user_rsp;
uint64_t user_ss;

void get_shell()
{
    if (getuid())
    {
        errExit("NO ROOT");
    }

    char *argv[] = {"/bin/sh", NULL};
    char *envp[] = {NULL};

    // logOK("Got shell!");
    execve(argv[0], argv, envp);
}

void hex_dump(char *buf, size_t size)
{
    for (size_t i = 0; i <= size / 8; i++)
    {
        printf("[+] buf[0x%04lx] -> 0x%016lx\n",
               i * 8,
               *(uint64_t *)&buf[i * 8]);
    }
}

void save_state()
{
    __asm__(
        "mov user_cs, cs;"
        "mov user_ss, ss;"
        "mov user_rsp, rsp;"
        "pushf;"
        "pop qword ptr [rip+user_rflags];");
    user_rip = (uint64_t)(uintptr_t)get_shell;
    logInfo("Saved user state - RIP: 0x%lx, CS: 0x%lx, RFLAGS: 0x%lx, RSP: 0x%lx, SS: 0x%lx",
            user_rip, user_cs, user_rflags, user_rsp, user_ss);
}

#endif /* KPWN_H */
