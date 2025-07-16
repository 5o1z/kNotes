**MSEA (Make Stack Execute Again)** có thể được gọi là một kĩ thuật giúp cho stack frame của chúng ta có quyền thực thi. Note này sẽ dựa trên blog [này]([Make Stack Executable Again | VulnX](https://vulnx.github.io/blog/posts/Make-Stack-Executable-Again/)) nhưng mình sẽ giải thích và demo lại theo cách hiểu của mình

## Description

Một vấn đề mà ta thường gặp đó chính là Stack Frame không phải lúc nào cũng thực thi được. Sẽ thuật tuyệt vời khi ta có thể craft được một cái ROP chain và có được shell từ nó. Nhưng sẽ ra sao nếu quá trình craft một ROP chain của chúng ta bị gián đoạn bởi một số thứ sau:

- ~~Quá ít gadgets có để có được shell~~ (Thường thì case này sẽ khá ít xảy ra, vì nếu ta có được libc leak rồi thì việc craft một ROP chain sẽ khá là đơn giản)
- Seccomp filter syscall `execve`
- Target của chúng ta không ở `filesystem` mà lại ở `memory`

Chính vì thế mà ở các trường hợp này, việc có được một Shellcode trong memory lại tốt hơn việc craft một ROP chain
## Idea
### mprotect

Phần lớn cách này sẽ sử dụng `mprotect` để cấp quyền `execute` cho stack:

```c
int mprotect(void *addr, size_t len, int prot);
```

`mprotect` cần 3 registers thiết yếu `RDI`, `RSI`, `RDX`. Nếu chúng ta có quyền kiểm soát 3 registers này thì ta có thể sử dụng `mprotect`, để cho stack có quyền `execute`. Nhưng còn có một cách nữa là ta chỉ cần sử kiểm soát đúng RDI, là ta có thể sử dụng được `mprotect`
### nptl_change_stack_perm

<Updating ...>

## PoC

```c
// gcc -o vuln vuln.c -g -fno-stack-protector
#include <stdio.h>

int main() {
	char buf[0x20];

	setvbuf(stdin,NULL,_IONBF,0);
	setvbuf(stdout,NULL,_IONBF,0);

	printf("Stack leak @ %p\n", (void *)buf);
	printf("Libc leak @ %p\n", (void *)setvbuf);

	// Buffer Overflow here
	read(0, buf, 0x500);

	return 0;
}
```
