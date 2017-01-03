/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			null_pointer.c	
=============================================================================*/ 
#include <stdio.h>


void foo(void)
{
	char name[4] = {'o','z','z','i'};
	printf("name:%s\n", name);
}

int main(int argc, char *argv[])
{
	foo();	

	return 0;
}
