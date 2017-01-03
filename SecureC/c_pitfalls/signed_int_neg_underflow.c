/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			signed_int_neg_underflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>

/* post validation */
void compliant_neg(signed int i_a)
{
	signed int r = -i_a;

	/* is a > INT_MIN ? 
	 * 
     */
	printf("%s() ", __FUNCTION__);
	if (i_a == INT_MIN){
		printf("underflow! ");
	}
	printf("r:%d\n", r);	
}



void neg(signed int i_a)
{
	signed int r = -i_a;

	printf("%s() ", __FUNCTION__);
	printf("r: %d\n", r);
}

int main(int argc, char *argv[])
{
	signed int a = 500;
	printf("a:%d\n", a);
	neg(a);
	compliant_neg(a);

	a = INT_MAX;
	printf("a:%d\n", a);
	neg(a);
	compliant_neg(a);

	a = INT_MIN;
	printf("a:%d\n", a);
	neg(a);
	compliant_neg(a);

	a = -1;
	printf("a:%d\n", a);
	neg(a);
	compliant_neg(a);
	return 0;
}
