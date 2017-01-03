/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			signed_int_overflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>

void compliant_sum(signed int i_a, signed int i_b)
{
	signed int r = i_a + i_b;

	/* is a+b > INT_MAX ?
	   is a+b < INT_MIN ?
	   if (a+b > INT_MAX) ?
	   if (a+b < INT_MIN) ?
	   if (a+b > INT_MAX || a+b < INT_MIN) ?
	   if (a > INT_MAX-b || a < INT_MIN-b) ?
     */
	printf("%s() ", __FUNCTION__);
	if (((i_b > 0) && (i_a > (INT_MAX - i_b))) || 
		((i_b < 0) && (i_a < (INT_MIN - i_b)))) {
		printf("underflow or overflow! ");
		printf("r:%d\n", r);
	} else {
		printf("r:%d\n", r);
	}

}



void sum(signed int i_a, signed int i_b)
{
	signed int r = i_a + i_b;

	printf("%s() ", __FUNCTION__);
	printf("r: %d\n", r);
}

int main(int argc, char *argv[])
{
	signed int a = 500;
	signed int b = -800;
	printf("a:%d\tb:%d\n", a, b);
	sum(a, b);
	compliant_sum(a, b);

	a = INT_MIN;
	b = -1;
	printf("a:%d\tb:%d\n", a, b);
	sum(a, b);
	compliant_sum(a, b);

	a = 1;
	b = INT_MAX;
	printf("a:%d\tb:%d\n", a, b);
	sum(a, b);
	compliant_sum(a, b);

	a = INT_MAX;
	b = INT_MAX;
	printf("a:%d\tb:%d\n", a, b);
	sum(a, b);
	compliant_sum(a, b);
	return 0;
}
