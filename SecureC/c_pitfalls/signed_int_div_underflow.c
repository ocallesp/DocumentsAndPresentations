/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			signed_int_div_underflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>

/* post validation */
void compliant_div(signed int i_a, signed int i_b)
{
	unsigned int r = 0;

	/* is b == 0  or  a/b < INT_MIN ? 
	 * is a == INT_MIN and b < -1
     */
	printf("%s() ", __FUNCTION__);
	if ((i_b == 0) || (i_a == INT_MIN && i_b < 0)){
		printf("underflow! \n");
	} else {
		r = i_a / i_b;
		printf("r:%d\n", r);	
	}

}



void div(signed int i_a, signed int i_b)
{
	unsigned int r = i_a / i_b;

	printf("%s() ", __FUNCTION__);
	printf("r: %d\n", r);
}

int main(int argc, char *argv[])
{
	signed int a = 500;
	signed int b = 800;
	printf("a:%d\tb:%d\n", a, b);
	div(a, b);
	compliant_div(a, b);

	a = INT_MAX;
	b = 0;
	printf("a:%d\tb:%d\n", a, b);
//	div(a, b);
	compliant_div(a, b);

	a = INT_MIN;
	b = -1;
	printf("a:%d\tb:%d\n", a, b);
//	div(a, b);
	compliant_div(a, b);

	a = INT_MAX;
	b = INT_MAX;
	printf("a:%d\tb:%d\n", a, b);
	div(a, b);
	compliant_div(a, b);
	return 0;
}
