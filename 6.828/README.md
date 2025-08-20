## Lab 1 - Booting a PC

### Part 1: PC Bootstrap

#### The PC's Physical Address Space

```
+------------------+  <- 0xFFFFFFFF (4GB)
|      32-bit      |
|  memory mapped   |
|     devices      |
|                  |
/\/\/\/\/\/\/\/\/\/\
/\/\/\/\/\/\/\/\/\/\
|                  |
|      Unused      |
|                  |
+------------------+  <- depends on amount of RAM
|                  |
| Extended Memory  |
|                  |
+------------------+  <- 0x00100000 (1MB)
|     BIOS ROM     |
+------------------+  <- 0x000F0000 (960KB)
|  16-bit devices, |
|  expansion ROMs  |
+------------------+  <- 0x000C0000 (768KB)
|   VGA Display    |
+------------------+  <- 0x000A0000 (640KB)
|                  |
|    Low Memory    |
|                  |
+------------------+  <- 0x00000000
```

- **0x00000000 ~ 0x0009FFFF (640KB):** Low Memory
- **0x000A0000 ~ 0x000FFFFF (384KB):** Reserved by Hardware
    > For special usages, such as video display buffers, firmware held in non-volatile memory. The most important part of this reserved area is the Basic Input/Output System (BIOS). BIOS occupied 64KB region from 0x000F0000 to 0x000FFFFF, which is responsible for performing basice system initialization and loading the OS from some appropriate location.

- **0x00100000 ~ RAM Size:** Extended Memory
    > Modern PCs supports 4GB physical address spaces or more but nevertheless preserved the early PCs' layout of low 1MB in order to ensure backward compatibility with existing software. Therefore, a "hole" from 0x000A0000 to 0x000FFFFF divides the RAM into low memory and extended memory.

#### ROM BIOS

**Functions**
- Set up interrupt descriptor table
- Initialize the VGA disaply, PCI bus and all important devices that BIOS knows
- Search the bootable device, read and transfer control to the boot loader

```gdb
$ make gdb
gdb -n -x .gdbinit
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
+ target remote localhost:26000
warning: No executable has been specified and target does not support
determining executable automatically.  Try using the "file" command.
The target architecture is set to "i8086".
[f000:fff0]    0xffff0: jmp    0x3630:0xf000e05b
0x0000fff0 in ?? ()
```

The following line:

```
[f000:fff0]    0xffff0: jmp    0x3630:0xf000e05b
```

is GDB's disassembly of the first instruction to be executed. From this output you can conclude a few things:

- The IBM PC starts executing at physical address `0x000ffff0`, which is at the very top of the 64KB area reserved for the ROM BIOS.
- The PC starts executing with `CS = 0xf000` and `IP = 0xfff0`.
- The first instruction to be executed is a jmp instruction, which jumps to the segmented address `CS = 0xf000` and `IP = 0xe05b`.

The real mode addressing `CS:IP` could be translated to a physical address by the formula: `physical address = 16 * segment(CS) + offset(IP)`. So that, `16 * 0xf000 + 0xfff0 = 0xffff0`. Therefore, the first thing that BIOS does is `jmp` backwards to an earlier location in the BIOS

### Part 2: The Boot Loader

Hard disks for PC are divided into 512 byte region called sectors. A sector is the hard disk's minimum granularity: each read/write operation must be one or more sectors in size and aligned on a sector boundary. If a disk is bootable, the first sector is called boot sector where the boot loader code resides.

BIOS finds the hard disk and loads the boot sector into memory at physical address `0x7c00`, then `jmp` to `CS:IP 0000:7c00`, passing control to the boot loader. The boot loader source files are `boot/boot.S` and `boot/main.c`. The disassembly of the boot loader after compilation is `obj/boot/boot.asm`, in which it tells the code layout in physical memory. Boot loader performs two main tasks:

- Switch from real mode to 32-bit protected mode so that software can access memory above 1MB. Now the physical address translation of `CS:IP` will be 32 bits instead of 16.
- Read kernel from the hard disk by directly accessing the IDE disk device registers via x86's special I/O instructions.

<details>
<summary><strong>Exercise 3</strong></summary>

1. At what point does the processor start executing 32-bit code? What exactly causes the switch from 16- to 32-bit mode?

    > At `ljmp    $PROT_MODE_CSEG, $protcseg` in `boot/boot.S`. The switch from 16-bit to 32-bit mode is caused by the `ljmp` instruction, which loads the new code segment and instruction pointer, effectively switching the processor into protected mode.

2. What is the last instruction of the boot loader executed?

    > ```x86asm
    > 0x7d19:      push   ebp
    > 0x7d1a:      mov    ebp,esp
    > 0x7d1c:      push   esi
    > 0x7d1d:      push   ebx
    > # readseg((uint32_t) ELFHDR, SECTSIZE*8, 0);
    > 0x7d1e:      push   edx
    > 0x7d1f:      push   0x0
    > 0x7d21:      push   0x1000
    > 0x7d26:      push   0x10000
    > 0x7d2b:      call   0x7cda
    > # if (ELFHDR->e_magic != ELF_MAGIC)
    > 0x7d30:      add    esp,0x10
    > 0x7d33:      cmp    DWORD PTR ds:0x10000,0x464c457f
    > 0x7d3d:      jne    0x7d77 ; Jump to bad
    > 0x7d3f:      mov    eax,ds:0x1001c # ELFHDR->e_phoff
    > 0x7d44:      movzx  esi,WORD PTR ds:0x1002c # ELFHDR->e_phnum
    > # ph = (struct Proghdr *) ((uint8_t *) ELFHDR + ELFHDR->e_phoff);
    > 0x7d4b:      lea    ebx,[eax+0x10000]
    > # eph = ph + ELFHDR->e_phnum;
    > 0x7d51:      shl    esi,0x5
    > 0x7d54:      add    esi,ebx
    > # for (; ph < eph; ph++)
    > 0x7d56:      cmp    ebx,esi
    > 0x7d58:      jae    0x7d71
    > 0x7d5a:      push   eax
    > 0x7d5b:      add    ebx,0x20
    > #      readseg(ph->p_pa, ph->p_memsz, ph->p_offset);
    > 0x7d5e:      push   DWORD PTR [ebx-0x1c]
    > 0x7d61:      push   DWORD PTR [ebx-0xc]
    > 0x7d64:      push   DWORD PTR [ebx-0x14]
    > 0x7d67:      call   0x7cda
    > 0x7d6c:      add    esp,0x10
    > 0x7d6f:      jmp    0x7d56
    > # ((void (*)(void)) (ELFHDR->e_entry))();
    > 0x7d71:      call   DWORD PTR ds:0x10018 ; The last instruction of the boot loader
    > ```

3. Where is the first instruction of the kernel?

    > ```gdb
    > (gdb) b *0x7d71
    > Breakpoint 1 at 0x7d71
    > (gdb) c
    > Continuing.
    > The target architecture is set to "i386".
    > => 0x7d71:      call   DWORD PTR ds:0x10018
    >
    > Breakpoint 1, 0x00007d71 in ?? ()
    > (gdb) si
    > => 0x10000c:    mov    WORD PTR ds:0x472,0x1234
    > 0x0010000c in ?? ()
    > (gdb) x/4i
    >    0x100015:    mov    eax,0x111000
    >    0x10001a:    mov    cr3,eax
    >    0x10001d:    mov    eax,cr0
    >    0x100020:    or     eax,0x80010001
    > ```
    > So the first instruction of the kernel is at physical address `0x0010000c`, which is the first instruction after the boot loader has loaded the kernel into memory.

4. How does the boot loader decide how many sectors it must read in order to fetch the entire kernel from disk? Where does it find this information?

    > Boot loader gets the program header table and number of entries from ELF header `ELFHDR + ELFHDR->e_phoff` and `ELFHDR->e_phnum` respectively.
    > ```c
    > ph = (struct Proghdr *) ((uint8_t *) ELFHDR + ELFHDR->e_phoff); // Program header table
    > eph = ph + ELFHDR->e_phnum; // End of program header table
    > for (; ph < eph; ph++)
    >   // p_pa is the load address of this segment (as well
    >   // as the physycal address)
    >   readseg(ph->p_pa, ph->p_memsz, ph->p_offset); // Read each segment
    > ```
</details>

#### Loading the Kernel

<details>
<summary><strong>Exercise 4</strong></summary>

```c
#include <stdio.h>
#include <stdlib.h>

void
f(void)
{
    int a[4];
    int *b = malloc(16);
    int *c;
    int i;

    printf("1: a = %p, b = %p, c = %p\n", a, b, c);

    c = a; // c point to the first element of a
    for (i = 0; i < 4; i++)
	    a[i] = 100 + i;
    c[0] = 200; // c[0] is equivalent to a[0] <-> a[0] = 200
    printf("2: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    c[1] = 300; // c[1] is equivalent to a[1] <-> a[1] = 300
    *(c + 2) = 301; // c[2] is equivalent to a[2] <-> a[2] = 301
    // Note: c[1] = 300, c[2] = 301
    3[c] = 302; // c[3] is equivalent to a[3] <-> a[3] = 302
    printf("3: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    c = c + 1; // c now points to a[1]
    *c = 400; // c[1] is equivalent to a[1] <-> a[1] = 400
    printf("4: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    c = (int *) ((char *) c + 1); // c now points to a[1] + 1 byte
    // Note: c is now pointing to a[1] + 1 byte, which is not a valid int address
    // so dereferencing c will cause undefined behavior.
    // However, we can still assign a value to c, which will not cause a crash
    // because it is just writing to a memory location that is not aligned.
    *c = 500; // This will change the value of a[1] + 1 byte, which is not a valid int address
    printf("5: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    b = (int *) a + 1; // b points to a[1]
    c = (int *) ((char *) a + 1); // c points to a[0] + 1 byte
    printf("6: a = %p, b = %p, c = %p\n", a, b, c);
}

int
main(int ac, char **av)
{
    f();
    return 0;
}
```

</details>

The compiler transforms each C source ('.c') file into an object ('.o') file containing assembly language instructions encoded in the binary format expected by the hardware. The linker then combines all of the compiled object files into a single binary image such as obj/kern/kernel, which in this case is a binary in the ELF format, which stands for "Executable and Linkable Format". For more information about ELF, see [ELF](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) and [the ELF specification](https://pdos.csail.mit.edu/6.828/2018/readings/elf.pdf).

An ELF binary starts with a fixed-length ELF header (inc/elf.h), followed by a variable-length program header listing each of the program sections to be loaded. There are some program sections that we care about:

- **.text**: Contains the executable code of the program.
- **.data**: Contains initialized global and static variables.
- **.rodata**: Contains read-only data, such as string literals.
- **.bss**: Contains uninitialized global and static variables, which are initialized to zero at runtime.
    > When the linker computes the memory layout of a program, it reserves space for uninitialized global variables, such as int x;, in a section called .bss that immediately follows .data in memory. C requires that "uninitialized" global variables start with a value of zero. Thus there is no need to store contents for .bss in the ELF binary; instead, the linker records just the address and size of the .bss section. The loader or the program itself must arrange to zero the .bss section.

```sh
$ objdump -x obj/boot/boot.out

obj/boot/boot.out:     file format elf32-i386
obj/boot/boot.out
architecture: i386, flags 0x00000012:
EXEC_P, HAS_SYMS
start address 0x00007c00

Program Header:
    LOAD off    0x00000074 vaddr 0x00007c00 paddr 0x00007c00 align 2**2
         filesz 0x00000228 memsz 0x00000228 flags rwx
   STACK off    0x00000000 vaddr 0x00000000 paddr 0x00000000 align 2**4
         filesz 0x00000000 memsz 0x00000000 flags rwx

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         0000018c  00007c00  00007c00  00000074  2**2
                  CONTENTS, ALLOC, LOAD, CODE
  1 .eh_frame     0000009c  00007d8c  00007d8c  00000200  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .stab         00000684  00000000  00000000  0000029c  2**2
                  CONTENTS, READONLY, DEBUGGING
  3 .stabstr      0000043f  00000000  00000000  00000920  2**0
                  CONTENTS, READONLY, DEBUGGING
  4 .comment      0000002b  00000000  00000000  00000d5f  2**0
                  CONTENTS, READONLY
SYMBOL TABLE:
00000000 l    df *ABS*  00000000 boot.o
00000008 l       *ABS*  00000000 PROT_MODE_CSEG
00000010 l       *ABS*  00000000 PROT_MODE_DSEG
00000001 l       *ABS*  00000000 CR0_PE_ON
00007c0a l       .text  00000000 seta20.1
00007c14 l       .text  00000000 seta20.2
00007c64 l       .text  00000000 gdtdesc
00007c32 l       .text  00000000 protcseg
00007c4a l       .text  00000000 spin
00007c4c l       .text  00000000 gdt
00000000 l    df *ABS*  00000000 main.c
00007c6a g     F .text  0000000e waitdisk
00007d19 g     F .text  00000073 bootmain
00007cda g     F .text  0000003f readseg
00007e28 g       .eh_frame      00000000 __bss_start
00007c78 g     F .text  00000062 readsect
00007e28 g       .eh_frame      00000000 _edata
00007e28 g       .eh_frame      00000000 _end
00007c00 g       .text  00000000 start
```

We have something to note:

- **VMA (or link address)** is the memory address from which the section expects to execute. The linker encodes the link address in the binary in various ways, such as when the code needs the address of a global variable, with the result that a binary usually won't work if it is executing from an address that it is not linked for. (It is possible to generate position-independent code that does not contain any such absolute addresses).

- **LMA (or load address)** is the memory address where the section is loaded into memory.

- The areas of the ELF object that need to be loaded into memory are those that are marked as "LOAD". Other information for each program header is given, such as the virtual address ("vaddr"), the physical address ("paddr"), and the size of the loaded area ("memsz" and "filesz").

- We find the `VMA=LMA=0x7c00`, which means that the BIOS loads the boot sector at the same address where it is expected to execute. The correct link address is set in the generated code by passing `-Ttext 0x7c00` to the linker in the `boot/Makefrag`.

- One field in the ELF header is also important, `e_entry` (inc/elf.h). It holds the link address of the `entry point` in the program, where the program should begin executing.

<details>
<summary><strong>Exercise 5</strong></summary>

> Trace through the first few instructions of the boot loader again and identify the first instruction that would "break" or otherwise do the wrong thing if you were to get the boot loader's link address wrong. Then change the link address in boot/Makefrag to something wrong, run make clean, recompile the lab with make, and trace into the boot loader again to see what happens. Don't forget to change the link address back and make clean again afterward!

The first instruction that would break if the link address is wrong is the `ljmp` instruction in `boot/boot.S` which switches us from 16 to 32 bits:

```x86asm
ljmp    $PROT_MODE_CSEG, $protcseg
```

To know the reason why it breaks, first take a look at [jmp instructions](https://www.felixcloutier.com/x86/jmp). In this case, we still in real mode
> `Far Jumps in Real-Address or Virtual-8086 Mode`. When executing a far jump in real-address or virtual-8086 mode, the processor jumps to the code segment and offset specified with the target operand. Here the target operand specifies an absolute far address either directly with a pointer (ptr16:16 or ptr16:32) or indirectly with a memory location (m16:16 or m16:32). With the pointer method, the segment and address of the called procedure is encoded in the instruction, using a 4-byte (16-bit operand size) or 6-byte (32-bit operand size) far address immediate. With the indirect method, the target operand specifies a memory location that contains a 4-byte (16-bit operand size) or 6-byte (32-bit operand size) far address. The far address is loaded directly into the CS and EIP registers. If the operand-size attribute is 16, the upper two bytes of the EIP register are cleared.

So if the link address is wrong, it will not be able to find the correct code segment where "intended" to be linked to execute and will cause error.

</details>

<details>
<summary><strong>Exercise 6</strong></summary>

> Examine the 8 words of memory at 0x00100000 at the point the BIOS enters the boot loader, and then again at the point the boot loader enters the kernel. Why are they different? What is there at the second breakpoint?

At the point the BIOS enters the boot loader:

```gdb
(gdb) x/8w 0x00100000
0x100000:       0x00000000      0x00000000      0x00000000      0x00000000
0x100010:       0x00000000      0x00000000      0x00000000      0x00000000
```

At the point when bootloader enters the kernel:

```gdb
(gdb) x/8w 0x00100000
0x100000:       0x1badb002      0x00000000      0xe4524ffe      0x7205c766
0x100010:       0x34000004      0x1000b812      0x220f0011      0xc0200fd8
(gdb) x/8i
   0x100020:    or     $0x80010001,%eax
   0x100025:    mov    %eax,%cr0
   0x100028:    mov    $0xf010002f,%eax
   0x10002d:    jmp    *%eax
   0x10002f:    mov    $0x0,%ebp
   0x100034:    mov    $0xf010f000,%esp
   0x100039:    call   0x1000a6
   0x10003e:    jmp    0x10003e
(gdb) x/8i 0x00100000
   0x100000:    add    0x1bad(%eax),%dh
   0x100006:    add    %al,(%eax)
   0x100008:    decb   0x52(%edi)
   0x10000b:    in     $0x66,%al
   0x10000d:    movl   $0xb81234,0x472
   0x100017:    adc    %dl,(%ecx)
   0x100019:    add    %cl,(%edi)
   0x10001b:    and    %al,%bl
```

Compare this with the boot loader code in `obj/kern/kernel.asm`:

```x86asm
.globl entry
entry:
 movw $0x1234,0x472   # warm boot
f0100000: 02 b0 ad 1b 00 00     add    0x1bad(%eax),%dh
f0100006: 00 00                 add    %al,(%eax)
f0100008: fe 4f 52              decb   0x52(%edi)
f010000b: e4                    .byte 0xe4

f010000c <entry>:
f010000c: 66 c7 05 72 04 00 00  movw   $0x1234,0x472
f0100013: 34 12
 # sufficient until we set up our real page table in mem_init
 # in lab 2.

 # Load the physical address of entry_pgdir into cr3.  entry_pgdir
 # is defined in entrypgdir.c.
 movl $(RELOC(entry_pgdir)), %eax
f0100015: b8 00 10 11 00        mov    $0x111000,%eax
 movl %eax, %cr3
f010001a: 0f 22 d8              mov    %eax,%cr3
 # Turn on paging.
 movl %cr0, %eax
f010001d: 0f 20 c0              mov    %cr0,%eax
 orl $(CR0_PE|CR0_PG|CR0_WP), %eax
f0100020: 0d 01 00 01 80        or     $0x80010001,%eax
 movl %eax, %cr0
f0100025: 0f 22 c0              mov    %eax,%cr0
```

we see that this is exactly the beginning of the code segment of the kernel. This makes sense because the bootloader loaded the kernel's .text section starting at the LMA (load address) 00100000:

```sh
$ objdump -h obj/kern/kernel

obj/kern/kernel:     file format elf32-i386

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         000019e1  f0100000  00100000  00001000  2**4
```

</details>
