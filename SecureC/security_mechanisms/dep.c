/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			dep.c
=============================================================================*/ 

/*
	Compile 
	$ gcc -z execstack dep.c -o dep

	Check stack is in RW
	$ objdump -M intel -d ./dep

*/

#include <stdio.h>
#include <string.h>

/*	
  4000cb:	b8 3c 00 00 00       	mov    eax, 0x3c    ; eax = 60
  4000d0:	bf 0b 00 00 00       	mov    edi, 0xb		; edi = 11
  4000d5:	0f 05                	syscall 			; exit(11)
*/
char shellcode[] = \
	"\xb8\x3c\x00\x00\x00"
	"\xbf\x0b\x00\x00\x00"
	"\x0f\x05";

int main()
{
  	printf("Shellcode Length:  %d\n", (int)strlen(shellcode));
	(*(void  (*)()) shellcode)();
	return 0;
}
