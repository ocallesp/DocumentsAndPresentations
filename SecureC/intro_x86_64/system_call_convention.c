/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			system_call_convention.c	
=============================================================================*/ 
/*
	gcc system_call_convention.c
	objdump -M intel -d ./a.out
	check how parameters are passed to foo
 */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void foo(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9, int var10)
{
	printf("foo()\n");

}

int main(int argc, char *argv[])
{
	foo(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);	

	return 0;
}
