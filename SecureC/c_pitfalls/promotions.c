/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			promotions.c	
=============================================================================*/ 
#include <stdio.h>
#include <stdint.h>

void compliant_shift(void)
{
	uint8_t port = 0x5a;
	uint8_t result_8 = (uint8_t) (~port) >> 4;

	printf("%s() ", __FUNCTION__);
	printf("result_8: %u\n", result_8);
}

void shift(void)
{
	uint8_t port = 0x5a;
	uint8_t result_8 = ( ~port ) >> 4;

	printf("%s() ", __FUNCTION__);
	printf("result_8: %u\n", result_8);
}


void compliant_int2uint(void)
{
	int i_a = -1;	/* Some signed value */;
	unsigned int ui_b = 1;/* Some unsigned value */;

	printf("%s() ", __FUNCTION__);
	if (i_a < 0 || (unsigned)i_a < ui_b) 
		printf("i_a < ui_b\n");
	else
		printf("i_a >= ui_b\n");

}

void int2uint(void)
{
	signed int i_a = -1; /* signed char c_a = -1 */
	unsigned int ui_b = 1;

	printf("%s() ", __FUNCTION__);
	if (i_a < ui_b)
		printf("i_a < ui_b\n");
	else
		printf("i_a >= ui_b\n");
}


void signed_chars(void)
{
	signed char c_r, c_a, c_b, c_c;
	c_a = 100;
	c_b = 3;
	c_c = 4;
	c_r = c_a * c_b / c_c;

	printf("%s() ", __FUNCTION__);
	printf("c_r: %d\n", c_r); /* <---- what is the output ?*/
}


void chars(void)
{
	char c_a = 10, c_b = 20;
	c_a = c_a + c_b;

	printf("%s() ", __FUNCTION__);
	printf("c_a: %d\n", c_a);/* <---- what is the output ? */
}



int main(int argc, char *argv[])
{
	chars();
	signed_chars();
	int2uint();
	compliant_int2uint();
	shift();
	compliant_shift();

	return 0;
}
