/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			unsigned_int_overflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>

void compliant_sum(unsigned int ui_a, unsigned int ui_b)
{
	unsigned int r = ui_a + ui_b;

	/* is a+b > UINT_MAX ? 
	 * if (UINT_MAX < a + b) ?
	 * if (UINT_MAX - a < b) ?
	 * if (a + b > UINT_MAX) ?
     */
	printf("%s() ", __FUNCTION__);
	if (ui_a > (UINT_MAX - ui_b)) {
		printf("overflow! ");
		printf("r:%u\n", r);
	} else {
		printf("r:%u\n", r);
	}

}



void sum(unsigned int ui_a, unsigned int ui_b)
{
	unsigned int r = ui_a + ui_b;

	printf("%s() ", __FUNCTION__);
	printf("r: %u\n", r);
}

int main(int argc, char *argv[])
{
	unsigned int a = 500;
	unsigned int b = 800;
	printf("a:%u\tb:%u\n", a, b);
	sum(a, b);
	compliant_sum(a, b);

	a = UINT_MAX;
	b = 1;
	printf("a:%u\tb:%u\n", a, b);
	sum(a, b);
	compliant_sum(a, b);

	a = 1;
	b = UINT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	sum(a, b);
	compliant_sum(a, b);

	a = UINT_MAX;
	b = UINT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	sum(a, b);
	compliant_sum(a, b);
	return 0;
}
