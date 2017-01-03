/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			strings_non_null_terminated.c	
=============================================================================*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char a[16] = {0};
	char b[16] = {0};
	char c[32] = {0};

	strncpy(a, "0123456789abcdef", sizeof(a));
	strncpy(b, "0123456789abcdef", sizeof(b));
	strncpy(c, a, sizeof(c));
	printf("c = %s\n", c);
}
