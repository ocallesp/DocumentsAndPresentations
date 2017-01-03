/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			unsigned_int_underflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>

void compliant_subs(unsigned int ui_a, unsigned int ui_b)
{
	unsigned int r = ui_a - ui_b;

	/* is a - b >= 0 ?    
       is a - b < 0 ?
	 * if (a - b < 0) ?
	 * if (b < a) ?
     */
	printf("%s() ", __FUNCTION__);
	if (ui_a < ui_b) {
		printf("underflow! ");
		printf("r:%u\n", r);
	} else {
		printf("r:%u\n", r);
	}

}



void subs(unsigned int ui_a, unsigned int ui_b)
{
	unsigned int r = ui_a - ui_b;

	printf("subs() ");
	printf("r: %u\n", r);
}

int main(int argc, char *argv[])
{
	unsigned int a = 500;
	unsigned int b = 800;
	printf("a:%u\tb:%u\n", a, b);
	subs(a, b);
	compliant_subs(a, b);

	a = UINT_MAX;
	b = 1;
	printf("a:%u\tb:%u\n", a, b);
	subs(a, b);
	compliant_subs(a, b);

	a = 1;
	b = UINT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	subs(a, b);
	compliant_subs(a, b);

	a = UINT_MAX;
	b = UINT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	subs(a, b);
	compliant_subs(a, b);
	return 0;
}
