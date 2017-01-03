/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:	    enum_signed_or_unsigned.c
=============================================================================*/ 
#include <stdio.h>


typedef enum {NON = 0, LUN = 1, MAR, MIE, JUE, VIE, SAB, DOM} Dias;
//typedef enum {NON = -1, LUN = 1, MAR, MIE, JUE, VIE, SAB, DOM} Dias;



int main(void)
{
	Dias hoy = LUN;
	
	printf("Today is %d\n", hoy);
	if (hoy < 0 && hoy > 7) {
		printf("Out of range: %d\n", hoy);
	}
	
	hoy = -1;
	if (hoy < 0) {
		printf("Negative - Out of range: %d\n", hoy);
	}
	if (hoy > 7) {
		printf("Too big - Out of range: %d\n", hoy);
	}

	hoy = -1;
	if ((signed int)hoy < 0) {
		printf("Negative - Out of range: %d\n", hoy);
	}
	if ((signed int)hoy > 7) {
		printf("Too big - Out of range: %d\n", hoy);
	}


	hoy = 8;
	if (hoy < 0) {
		printf("Negative - Out of range: %d\n", hoy);
	}
	if (hoy > 7) {
		printf("Too big - Out of range: %d\n", hoy);
	}
	
	return 0;
}
