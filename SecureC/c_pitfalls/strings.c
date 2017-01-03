/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			strings.c	
=============================================================================*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char *buff = (char *)malloc(strlen(argv[1])+1);
	if (buff != NULL) {
		strcpy(buff, argv[1]);
		printf("argv[1] = %s.\n", buff);
	}
	else {
		/* Couldn't get the memory - recover */
	}	

	return 0;
}
