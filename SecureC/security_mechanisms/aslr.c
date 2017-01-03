/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			aslr.c	
=============================================================================*/ 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
	0 – No randomization.
	1 – Partial randomization. Shared libraries, stack, mmap(), VDSO and heap are randomized.
	2 – Full randomization. In addition to elements listed in the previous point, memory managed through brk() is also randomized.

	sudo bash -c "echo 0 > /proc/sys/kernel/randomize_va_space"
	gcc -pie -fPIE aslr.c 
 */

const int const_value = 23;

void foo(void)
{
	return;
}

int main(int argc, char *argv[])
{
	int var;
	int *ptr = NULL;
	printf("&var: %p\n", &var);
	printf("foo(): %p\n", foo);
	printf("write(): %p\n", write);
	printf("printf(): %p\n", printf);
	ptr = malloc(10);
	printf("ptr:%p\n", ptr);
	printf("const_value:%p\n", &const_value);
	return 0;
}
