/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			stack_canaries.c
=============================================================================*/ 
#include <stdio.h>
#include <unistd.h>

/*
	stack canary implementation
	https://sourceware.org/git/?p=glibc.git;a=blob;f=debug/stack_chk_fail.c;h=9ab9bc7cebf7ed21a13af29c860ae683ea0d29e6;hb=ed421fca42fd9b4cab7c66e77894b8dd7ca57ed0

	Add stack canaires in dangerous functions
	$ gcc -fstack-protector  stack_canaries.c -o stack_canaries

	Add stack canaries in all functions
	$ gcc -fstack-protector-all  stack_canaries.c -o stack_canaries

	Disable stack canaries
	$ gcc -fno-stack-protector  stack_canaries.c -o stack_canaries

	$ objdump -M intel -d ./stack_canaries
*/

void foo2(void)
{
	int var;
}


void foo(void)
{
	char buff[8];
	
	return;
}

int main(int argc, char *argv[])
{

	foo();
	foo2();	
	return 0;
}
