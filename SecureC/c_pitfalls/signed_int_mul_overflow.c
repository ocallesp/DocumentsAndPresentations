/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			unsigned_int_mul_overflow.c
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>
#include <assert.h>

void compliant_mul2(signed int i_a, signed int i_b) {
	signed int result;
	signed long tmp;

	printf("%s() ", __FUNCTION__);
	assert(sizeof(tmp) >= 2 * sizeof(result) && "size of tmp cannot contain result");
	tmp = (signed long long)i_a * (signed long long)i_b;
	/*
	 * If the product cannot be represented as a 32-bit integer,
	 * handle as an error condition.
	 */

	if ((tmp > INT_MAX) || (tmp < INT_MIN)) {
		printf("overflow! ");
	} else {
		result = (int)tmp;
	}
	printf("result: %d\n", result);
}




/* post validation */
void compliant_mul(signed int i_a, signed int i_b)
{
	signed int result;

	printf("%s() ", __FUNCTION__);
	if (i_a > 0) { 		/* i_a is positive */
		if (i_b > 0) { 	/* i_a and i_b are positive */
			if (i_a > (INT_MAX / i_b)) {
				printf("overflow! ");
			}
		} else { /* i_a positive, i_b nonpositive */
			if (i_b < (INT_MIN / i_a)) {
				printf("underflow! ");
			}
		} /* i_a positive, i_b nonpositive */
	} else { /* i_a is nonpositive */
		if (i_b > 0) { /* i_a is nonpositive, i_b is positive */
			if (i_a < (INT_MIN / i_b)) {
				printf("underflow! ");
			}
		} else { /* i_a and i_b are nonpositive */
			if ( (i_a != 0) && (i_b < (INT_MAX / i_a))) {
				printf("overflow! ");
			}
		} /* End if i_a and i_b are nonpositive */
	} /* End if i_a is nonpositive */
	
	result = i_a * i_b;
	printf("result: %d\n", result);
}



void mul(signed int i_a, signed int i_b)
{
	unsigned int r = i_a * i_b;

	printf("%s() ", __FUNCTION__);
	printf("s: %u\n", r);
}

int main(int argc, char *argv[])
{
	signed int a = 500;
	signed int b = 800;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);
	compliant_mul2(a, b);

	a = INT_MAX;
	b = 5;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);
	compliant_mul2(a, b);

	a = -5;
	b = INT_MAX;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);
	compliant_mul2(a, b);

	a = INT_MAX;
	b = INT_MIN;
	printf("a:%u\tb:%u\n", a, b);
	mul(a, b);
	compliant_mul(a, b);
	compliant_mul2(a, b);
	return 0;
}
