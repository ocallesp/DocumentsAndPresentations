/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			off_by_one.c
=============================================================================*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 16 characters + 1 NUL character
const char *source = "0123456789abcdef";

void vuln2(void)
{
	int i = 0;
	int len = 0;
	// calculates the length of the string s, 
	// excluding the terminating null byte ('\0')
	len = strlen(source);
	printf("len:%d\n", len);
	char *dest = (char *)malloc(len); // strlen = 16, index 0 to 15
	for (i=0; i <= 15; i++) {
		dest[i] = source[i];	
	}
	printf("i:%d\n", i);
	dest[i] = '\0';
	printf("dest = %s\n", dest);
}


void vuln(void)
{
	char dest[16];
	// function copies the string pointed to by src, 
	// including the terminating null byte ('\0')
	strcpy(dest, source); 	// 16 characters

	printf("dest = %s\n", dest);
}


int main(int argc, char *argv[])
{
	printf("vuln()\n");
	vuln();
	printf("vuln2()\n");
	vuln2();

	return 0;
}
