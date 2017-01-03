/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			sizeof.c
=============================================================================*/ 
#include <stdio.h>

struct data {
	/* empty */
};

int main(int argc, char *argv[])
{
	printf("size of data types\n");
	printf("char:%lu\n", sizeof(char));	
	printf("int:%lu\n", sizeof(int));	
	printf("long:%lu\n", sizeof(long));	
	printf("float:%lu\n", sizeof(float));	
	printf("double:%lu\n", sizeof(double));	
	printf("long long:%lu\n", sizeof(long long));	
	printf("struct data:%lu\n", sizeof(struct data));	

	return 0;
}
