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

### Part 3: The Kernel

#### Using virtual memory to work around position dependence

Unlike boot load, the link address and load address are different for kernel. OS kernel often like to be linked and run at high virtual address (VA), e.g. 0xf0100000, in order to leave the lower part of processor's VA space for user programs to use.

But many machines don't have any physical memory at that high address. So memory management unit (MMU) is employed to map virtual address 0xf0100000 (VMA) to physical address 0x00100000 (LMA).

For now, we just map the first 4MB of physical memory by using the statically-initialized page directory and page table in `kern/entrypgdir.c`. Once the `CR0_PG` is set in the `kern/entry.S`, memory references are `VAs`. Before that, they are physical addresses. `entry_pgdir` in the `kern/entrypgdir.c` translates the VA in the ranges of `[0x00000000, 0x00400000]` and `[0xf0000000, 0xf0400000]` to physical address `[0x00000000, 0x00400000]`. Access to the VA not in the two ranges will cause a hardware exception.

<details>
<summary><strong>Exercise 7</strong></summary>

> Use QEMU and GDB to trace into the JOS kernel and stop at the movl %eax, %cr0. Examine memory at 0x00100000 and at 0xf0100000. Now, single step over that instruction and examine memory at 0x00100000 and at 0xf0100000 again.

View the file `obj/kern/kernel.asm` we know that our instruction is place at `0x00100025` before the VA is turned on:

```gdb
(gdb) b *0x100025
Breakpoint 1 at 0x100025
(gdb) c
Continuing.
The target architecture is set to "i386".
=> 0x100025:    mov    cr0,eax
```

Check the memory at `0x00100000` and `0xf0100000`:

```gdb
(gdb) x/10w 0x00100000
0x100000:       0x1badb002      0x00000000      0xe4524ffe      0x7205c766
0x100010:       0x34000004      0x1000b812      0x220f0011      0xc0200fd8
0x100020:       0x0100010d      0xc0220f80
(gdb) x/10w 0xf0100000
0xf0100000 <_start-268435468>:  Cannot access memory at address 0xf0100000
```

After turn on paging:

```gdb
(gdb) si
=> 0x100028:    mov    eax,0xf010002f
(gdb) x/10w 0xf0100000
0xf0100000 <_start-268435468>:  0x1badb002      0x00000000      0xe4524ffe      0x7205c766
0xf0100010 <entry+4>:   0x34000004      0x1000b812      0x220f0011      0xc0200fd8
0xf0100020 <entry+20>:  0x0100010d      0xc0220f80
(gdb) x/10w 0x00100000
0x100000:       0x1badb002      0x00000000      0xe4524ffe      0x7205c766
0x100010:       0x34000004      0x1000b812      0x220f0011      0xc0200fd8
0x100020:       0x0100010d      0xc0220f80
```

As we can see, after the paging is turned on, the memory at `0xf0100000` is now accessible and contains the same data as the memory at `0x00100000`. This is because the page directory and page table map the virtual address `0xf0100000` to the physical address `0x00100000`, allowing us to access the kernel code at a high virtual address while it is actually loaded at a lower physical address. And those instructions at `0xf0100000` are the same as those at `0x00100000`, which is the kernel code.

```gdb
(gdb) x/11i 0xf0100000
   0xf0100000 <_start-268435468>:       add    dh,BYTE PTR [eax+0x1bad]
   0xf0100006 <_start-268435462>:       add    BYTE PTR [eax],al
   0xf0100008 <_start-268435460>:       dec    BYTE PTR [edi+0x52]
   0xf010000b <_start-268435457>:       in     al,0x66
   0xf010000d <entry+1>:        mov    DWORD PTR ds:0x472,0xb81234
   0xf0100017 <entry+11>:       adc    BYTE PTR [ecx],dl
   0xf0100019 <entry+13>:       add    BYTE PTR [edi],cl
   0xf010001b <entry+15>:       and    bl,al
   0xf010001d <entry+17>:       mov    eax,cr0
   0xf0100020 <entry+20>:       or     eax,0x80010001
   0xf0100025 <entry+25>:       mov    cr0,eax
(gdb) x/11i 0x00100000
   0x100000:    add    dh,BYTE PTR [eax+0x1bad]
   0x100006:    add    BYTE PTR [eax],al
   0x100008:    dec    BYTE PTR [edi+0x52]
   0x10000b:    in     al,0x66
   0x10000d:    mov    DWORD PTR ds:0x472,0xb81234
   0x100017:    adc    BYTE PTR [ecx],dl
   0x100019:    add    BYTE PTR [edi],cl
   0x10001b:    and    bl,al
   0x10001d:    mov    eax,cr0
   0x100020:    or     eax,0x80010001
   0x100025:    mov    cr0,eax
```

> What is the first instruction after the new mapping is established that would fail to work properly if the mapping weren't in place? Comment out the movl %eax, %cr0 in kern/entry.S, trace into it, and see if you were right.

```gdb
(gdb) b *0x0100020
Breakpoint 1 at 0x100020
(gdb) c
Continuing.
The target architecture is set to "i386".
=> 0x100020:    or     $0x80010001,%eax

Breakpoint 1, 0x00100020 in ?? ()
(gdb) x/2i
   0x100025:    mov    $0xf010002c,%eax
   0x10002a:    jmp    *%eax
(gdb) si
=> 0x100025:    mov    $0xf010002c,%eax
0x00100025 in ?? ()
(gdb)
=> 0x10002a:    jmp    *%eax
0x0010002a in ?? ()
(gdb)
=> 0xf010002c <relocated>:      Error while running hook_stop:
Cannot access memory at address 0xf010002c
relocated () at kern/entry.S:74
74              movl    $0x0,%ebp                       # nuke frame pointer
```

So the first instruction fail if we comment out the turn on paging is the `movl    $0x0,%ebp`. The reason why it fails is that the prior instruction made us jump to address 0xf010002c. Because paging is not enabled, this address is interpeted as a physical address, and since there is no RAM inside of it, qemu crashes. Indeed if we look at the qemu output, we see: `fatal: Trying to execute code outside RAM or ROM at 0xf010002c`

</details>

#### Formatted Printing to the Console

<details>
<summary><strong>Exercise 8</strong></summary>

0. We have omitted a small fragment of code - the code necessary to print octal numbers using patterns of the form "%o". Find and fill in this code fragment.

    > ```c
    > // (unsigned) octal
    > case 'o':
    >       num = getuint(&ap, lflag); // Get the number
    >       base = 8; // Set base to octal
    >       goto number;
    > ```
    > With this addition, we will recive the message: `6828 decimal is 15254 octal!` when we run the `qemu` after recompiling. This message is come from `cprintf("6828 decimal is %o octal!\n", 6828);` in >`i386_init()`

1. Explain the interface between printf.c and console.c. Specifically, what function does console.c export? How is this function used by printf.c?
    > `console.c` exports the function `cputchar(int c)`, which is a low level routine puts a character in the serial port, the parallel port, and in the CGA buffer, which appears on the screen. `printf.c` uses this function to output characters when formatting strings, integers, and other data types. `printf.c` has a function putch(int ch, int* cnt) that uses this cputchar function exposed by console.c. It is worth mentioning that the useful function cprintf actually passes putch to vprintfmt which accepts a "generic function that prints a character".

2. Explain the following code from console.c.

    >```c
    >    // If screen is full, scroll down CRT_COLS characters
    >    if (crt_pos >= CRT_SIZE) {
    >            int i;
    >            // Push out CRT_COLS of data from the beginning of the display buffer
    >            memmove(crt_buf, crt_buf + CRT_COLS, (CRT_SIZE - CRT_COLS) * sizeof(uint16_t));
    >            // Erase the previous characters at the end
    >            for (i = CRT_SIZE - CRT_COLS; i < CRT_SIZE; i++)
    >                    crt_buf[i] = 0x0700 | ' ';
    >            // Move position back to the current end
    >            crt_pos -= CRT_COLS;
    >    }
    >```
    > Read [this](https://github.com/Babtsov/jos/tree/master/lab1#be-able-to-answer-the-following-questions) for more explaination

3. In the call to cprintf(), to what does fmt point? To what does ap point?

    > So first we need to put these code in `kern/init.c` inside the `i386_init()` function:
    >
    > ```c
    >     cons_init();
    >
    >     cprintf("6828 decimal is %o octal!\n", 6828);
    >
    >     /* QUESTION 3 CODE START */
    >     int x = 1, y = 3, z = 4;
    >     cprintf("x %d, y %x, z %d\n", x, y, z);
    >     /* QESTION 3 CODE END*/
    > ```
    >
    > Recompile the kernel and debug it with gdb, remember to set the breakpoint at the call `cprintf`, in my case it is at `f01000e8`:
    >
    > ```gdb
    > (gdb) b *0xf01000e8
    > Breakpoint 1 at 0xf01000e8: file kern/init.c, line 40.
    > (gdb) c
    > Continuing.
    > The target architecture is set to "i386".
    > => 0xf01000e8 <i386_init+66>:   push   $0x4
    >
    > Breakpoint 1, i386_init () at kern/init.c:40
    > 40          cprintf("x %d, y %x, z %d\n", x, y, z);
    > (gdb) x/5i
    >    0xf01000ea <i386_init+68>:   push   $0x3
    >    0xf01000ec <i386_init+70>:   push   $0x1
    >    0xf01000ee <i386_init+72>:   lea    -0xe876(%ebx),%eax
    >    0xf01000f4 <i386_init+78>:   push   %eax
    >    0xf01000f5 <i386_init+79>:   call   0xf0100a49 <cprintf>
    > ```
    >
    > Set another breakpoint at `0xf0100a56` which is the call to `vcprintfmt`:
    >
    > ```gdb
    > (gdb) b *0xf0100a56
    > Breakpoint 2 at 0xf0100a56: file kern/printf.c, line 32.
    > (gdb) c
    > Continuing.
    > => 0xf0100a56 <cprintf+13>:     call   0xf0100a12 <vcprintf>
    >
    > Breakpoint 2, 0xf0100a56 in cprintf (fmt=0xf0101a92 "x %d, y %x, z %d\n") at kern/printf.c:32
    > 32              cnt = vcprintf(fmt, ap);
    > (gdb) si
    > => 0xf0100a12 <vcprintf>:       push   %ebp
    > vcprintf (fmt=0xf0101a92 "x %d, y %x, z %d\n", ap=0xf010efd4 "\001") at kern/printf.c:18
    > (gdb) x/12w 0xf010efa8 # 0xf010efa8 is the address pointed by esp
    > 0xf010efa8:     0xf010efc8      0xf0100a5b      0xf0101a92      0xf010efd4
    > 0xf010efb8:     0xf010efd8      0xf0100a5b      0xf0101a77      0xf010efe4
    > 0xf010efc8:     0xf010eff8      0xf01000fa      0xf0101a92      0x00000001
    > (gdb) x/s 0xf0101a92
    > 0xf0101a92:     "x %d, y %x, z %d\n"
    > (gdb) x/s 0xf010efd4
    > 0xf010efd4:     "\001"
    > (gdb) x/s 0xf010efd8
    > 0xf010efd8:     "\003"
    > (gdb) x/s 0xf010efd8+0x4
    > 0xf010efdc:     "\004"
    > ```
    >
    > After stepping into `vcprintf`, we can see that `fmt` points to the string "x %d, y %x, z %d\n" (`0xf0101a92`) and`ap` points to the stack location (`0xf010efd4`) where the arguments are stored. The`ap` is a pointer to the argument list, which is used to access the variable arguments passed to the function.

</details>

<details>
<summary><strong>Challenge: Enhance the console</strong></summary>

> ```c
> /* kern/init.c - i386_init() */
> /* 0 (all off), 1 (bold), 4 (underscore), 31 (red foreground), 43 (yellow background) */
> cprintf("Lab1-Ch: \033[1;4;31;43mHello colorful world! \033[0m\n");
> ```

</details>

#### The Stack

ESP (stack pointer): always points to the top (lowest address) of the current stack frame.

- push: esp -= 4 then write value at [esp].
- pop: read [esp] then esp += 4.
- In 32-bit mode: stack entries are 32 bits; ESP is 4-byte aligned.
- Certain instructions (e.g., call/ret, interrupts) are hard-wired to use ESP.

EBP (frame/base pointer): a convention, not hardware-enforced.

- Typical C prologue: push ebp; mov ebp, esp (save caller’s EBP, set current frame base).
- With this convention, saved EBP values form a linked list of frames, enabling reliable stack backtraces (who called whom), great for debugging bad-arg crashes/asserts.

Bottom line: ESP manages the live stack mechanics; EBP provides a stable anchor for locals/args and backtracing (if the compiler doesn’t omit frame pointers).

<details>
<summary><strong>Exercise 9</strong></summary>

> Determine where the kernel initializes its stack, and exactly where in memory its stack is located. How does the kernel reserve space for its stack? And at which "end" of this reserved area is the stack pointer initialized to point to?

The kernel initializes its stack at in entry.S by executing the following line: `movl    $(bootstacktop),%esp`, which `bootstacktop` address is defined in the `.data` section at the offset equal to `KSTKSIZE` (see at the bottom of `entry.S` source code). Because the stack grows down, `bootstacktop` is where the stack pointer will initially point to and it will grow towards lower addresses of the `.data` section. To be more concrete where in memory the stack is located, let's first find the `.data` section:

```sh
$ objdump -h obj/kern/kernel | grep -B 1 ' .data'
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .data         00009300  f0107000  00107000  00008000  2**12
```

And from `inc/memlayout.h`, we know that `KSTKSIZE = 8 * PGSIZE = 8 * 4096 = 32768` bytes, So the stack is allocated the address range is from `0xf0107000 to 0xf010f000`, and thus, `$esp` will initially point to `0xf010f000` (which is the actual value of KSTKSIZE). You can verify by viewing the `obj/kern/kernel.asm`:

```x86asm
    # Set the stack pointer
    movl $(bootstacktop),%esp
f0100034: bc 00 f0 10 f0        mov    $0xf010f000,%esp
```

</details>


<details>
<summary><strong>Exercise 10</strong></summary>

> To become familiar with the C calling conventions on the x86, find the address of the test_backtrace function in obj/kern/kernel.asm, set a breakpoint there, and examine what happens each time it gets called after the kernel starts. How many 32-bit words does each recursive nesting level of test_backtrace push on the stack, and what are those words?

```x86asm
f01000a6 <i386_init>:

void
i386_init(void)
{
// [...]
    // Test the stack backtrace function (lab 1 only)
 test_backtrace(5);
f0100109: c7 04 24 05 00 00 00  movl   $0x5,(%esp)
f0100110: e8 2b ff ff ff        call   f0100040 <test_backtrace>
f0100115: 83 c4 10              add    $0x10,%esp

 // Drop into the kernel monitor.
 while (1)
  monitor(NULL);
f0100118: 83 ec 0c              sub    $0xc,%esp
f010011b: 6a 00                 push   $0x0
f010011d: e8 7c 07 00 00        call   f010089e <monitor>
// [...]
}

f0100040 <test_backtrace>:
#include <kern/console.h>
// Test the stack backtrace function (lab 1 only)
void test_backtrace(int x) {
f0100040: 55                    push   %ebp
f0100041: 89 e5                 mov    %esp,%ebp
f0100043: 53                    push   %ebx
f0100044: 83 ec 14              sub    $0x14,%esp
f0100047: 8b 5d 08              mov    0x8(%ebp),%ebx
     cprintf("entering test_backtrace %d\n", x);
// [...]
}
```

Here is what happens each time `test_backtrace` is called:

- `call   f0100040 <test_backtrace>`: Push the 4 bytes of the next instruction (the return address) onto the stack.
- `push   %ebp`: Push the old base pointer (4 bytes) onto the
- `mov    %esp,%ebp`: Set the base pointer to the current stack pointer (ESP).
- `push   %ebx`: Push the value of the EBX register (4 bytes) onto the stack.
- `sub    $0x14,%esp`: Create 0x14 bytes space on the stack for local variables and saved registers.
    > 0x14 / 4 = 5, so 5 dwords is a stack frame size for each call to `test_backtrace`.

</details>

Some important notes about pointer:

- If int `*p = (int*)100`, then `(int)p + 1` and `(int)(p + 1)` are different numbers: the first is 101 but the second is 104. When adding an integer to a pointer, as in the second case, the integer is implicitly multiplied by the size of the object the pointer points to.
- `p[i]` is defined to be the same as `*(p+i)`, referring to the i'th object in the memory pointed to by p. The above rule for addition helps this definition work when the objects are larger than one byte.
- `&p[i]` is the same as `(p+i)`, yielding the address of the i'th object in the memory pointed to by p.

<details>
<summary><strong>Exercise 11</strong></summary>

> Implement the backtrace function mon_backtrace()


Set a breakpoint at `0xf0100093` which is after a `test_backtrace` recursion, `c` and view the value of `ebp`:

```gdb
(gdb) b *0xf0100093
Breakpoint 1 at 0xf0100093: file kern/init.c, line 18.
(gdb) c
Continuing.
The target architecture is set to "i386".
=> 0xf0100093 <test_backtrace+83>:      sub    $0x4,%esp

Breakpoint 1, test_backtrace (x=0) at kern/init.c:18
18                      mon_backtrace(0, 0, 0);
(gdb) i f
Stack level 0, frame at 0xf010ef40:
 eip = 0xf0100093 in test_backtrace (kern/init.c:18); saved eip = 0xf0100076
 called by frame at 0xf010ef60
 source language c.
 Arglist at 0xf010ef38, args: x=0
 Locals at 0xf010ef38, Previous frame's sp is 0xf010ef40
 Saved registers:
  ebx at 0xf010ef30, ebp at 0xf010ef38, esi at 0xf010ef34, eip at 0xf010ef3c
(gdb) x/8xw 0xf010ef38
0xf010ef38:     0xf010ef58      0xf0100076      0x00000000      0x00000001
0xf010ef48:     0xf010ef78      0xf010004a      0xf0110308      0x00000002
(gdb) x/8xw 0xf010ef58
0xf010ef58:     0xf010ef78      0xf0100076      0x00000001      0x00000002
0xf010ef68:     0xf010ef98      0xf010004a      0xf0110308      0x00000003
(gdb) x/8xw 0xf010ef78
0xf010ef78:     0xf010ef98      0xf0100076      0x00000002      0x00000003
0xf010ef88:     0xf010efb8      0xf010004a      0xf0110308      0x00000004
(gdb) x/8xw 0xf010ef98
0xf010ef98:     0xf010efb8      0xf0100076      0x00000003      0x00000004
0xf010efa8:     0xf010efc8      0xf010004a      0xf0110308      0x00000005
(gdb) x/8xw 0xf010efb8
0xf010efb8:     0xf010efd8      0xf0100076      0x00000004      0x00000005
0xf010efc8:     0xf010eff8      0xf010004a      0xf0110308      0x00010094
(gdb) x/8xw 0xf010efd8
0xf010efd8:     0xf010eff8      0xf0100115      0x00000005      0x00001aac
0xf010efe8:     0x00000660      0x00000000      0x00000000      0x00010094
(gdb) x/8xw 0xf010eff8
0xf010eff8:     0x00000000      0xf010003e      0x00000003      0x00001003
0xf010f008 <entry_pgtable+8>:   0x00002003      0x00003003      0x00004003      0x00005003
```

So the idea are:
1. First read the value of the base pointer (EBP) from the current stack frame (which is a base pointer of caller).
2. According to that base pointer, we can find the instruction pointer (EIP) of the previous call, which is stored at the address `ebp + 4`.
3. The arguments of the previous call are stored at `ebp + 8`, `ebp + 12`, `ebp + 16`, `ebp + 20`, and `ebp + 24`.
4. Continue this process until we reach the base pointer of the first call, which is 0.

```c
int
mon_backtrace(int argc, char **argv, struct Trapframe *tf)
{
    uint32_t ebp  // Get the value of base pointer

    cprintf("Stack backtrace:\n");

    while (ebp != 0)
    {
        uint32_t eip = *((uint32_t *)ebp + 1);
        cprintf("ebp %08x eip %08x args", ebp, eip);

        for (int i = 2; i < 7; i++) {
            cprintf(" %08x", *((uint32_t *)ebp + i));
        }
        cprintf("\n");
        ebp = *(uint32_t *)ebp;
    }

    return 0;
}
```

</details>

<details>
<summary><strong>Exercise 12</strong></summary>

> Modify your stack backtrace function to display, for each eip, the function name, source file name, and line number corresponding to that eip.

The complete code of `mon_backtrace` is at [`kern/monitor.c`](kern/monitor.c#L58-L86). And the code of `kdebug.c` is at [`kern/kdebug.c`](kern/kdebug.c#L183-L91).

</details>

### Further Reading

- Linker documentation: <http://www.scoberlin.de/content/media/http/informatik/gcc_docs/ld_3.html>
- Stabs doumentation: <https://sourceware.org/gdb/current/onlinedocs/stabs.html#Symbol-Tables>
- More info about stabs from ibm: <https://www.ibm.com/developerworks/library/os-debugging/index.html>
