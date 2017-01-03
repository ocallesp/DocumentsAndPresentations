/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			unsigned_int_mul_overflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>

/* post validation */
void compliant_mul(unsigned int ui_a, unsigned int ui_b)
{
	unsigned int r = ui_a * ui_b;

	/* is a*b > UINT_MAX ? 
	 * if (UINT_MAX < a * b) ?
	 * if (b > UINT_MAX/a) ?
     */
	if (ui_a == 0 || ui_b == 0) {
		printf("s:%u\n", r);
		return;
	}

	printf("%s() ", __FUNCTION__);
	if (ui_a > (UINT_MAX/ui_b)) {
		printf("overflow! ");
		printf("s:%u\n", r);
	} else {
		printf("s:%u\n", r);
	}

}



void mul(unsigned int ui_a, unsigned int ui_b)
{
	unsigned int r = ui_a * ui_b;

	printf("%s() ", __FUNCTION__);
	printf("s: %u\n", r);
}

int main(int argc, char *argv[])
{
	unsigned int a = 500;
	unsigned int b = 800;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);

	a = UINT_MAX;
	b = 0;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);

	a = 0;
	b = UINT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);

	a = UINT_MAX;
	b = UINT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);
	return 0;
}
