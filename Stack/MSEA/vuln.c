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