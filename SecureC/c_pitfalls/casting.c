/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			casting.c	
=============================================================================*/ 
#include <stdio.h>
#include <limits.h>


// This might chage, this data type depends on implementation
//typedef unsigned int my_type;
typedef int my_type;

my_type foo(void)
{
	my_type a = -1;
	return a;
}

void check_foo(void)
{
	my_type r = foo();

	printf("%s() ", __FUNCTION__);
	if (r == (my_type)-1)
		printf("r == -1\n");
	else 
		printf("r != -1\n");
}


void compliant_copy_long2char(void)
{
	signed long int l_a = LONG_MAX;
	signed char c_b;

	printf("%s() ", __FUNCTION__);
	if ((l_a < SCHAR_MIN) || (l_a > SCHAR_MAX)) {
		printf("cannot copy l_a to c_b! \n");
	} else {
		c_b = (signed char)l_a; /* Use cast to eliminate warning */
		printf("c_b: %d\n", c_b);
	}

}


void copy_long2char(void)
{
	signed long int l_a = LONG_MAX;
	signed char c_b = (signed char)l_a; /* Cast eliminates warning */

	printf("%s() ", __FUNCTION__);
	printf("c_b: %d\n", c_b);
}

void compliant_copy_int2uint(void)
{
	signed int i_a = INT_MIN;
	unsigned int ui_b;

	printf("%s() ", __FUNCTION__);
	if (i_a < 0) {
		printf("cannot copy u_a to c_b! \n");
	} else {
		ui_b = (unsigned int)i_a;
		printf("ui_b: %u\n", ui_b);
	}
}

void copy_int2uint(void)
{
	signed int i_a = INT_MIN;
	/* Cast eliminates warning */
	unsigned int ui_b = (unsigned int)i_a;

	printf("%s() ", __FUNCTION__);
	printf("ui_b: %u\n", ui_b);
}


void compliant_copy_int2char(void)
{
	unsigned long int u_a = ULONG_MAX;
	signed char c_b;

	printf("%s() ", __FUNCTION__);
	if (u_a <= SCHAR_MAX) {
		c_b = (signed char)u_a; /* Cast eliminates warning */
		printf("c_b: %d\n", c_b);
	} else {
		printf("cannot copy u_a to c_b!\n");
	}
}


void copy_int2char(void)
{
	unsigned long int u_a = ULONG_MAX;
	signed char c_b;
	c_b = (signed char)u_a; /* Cast eliminates warning */

	printf("%s() ", __FUNCTION__);
	printf("c_b: %d\n", c_b);
}

int main(int argc, char *argv[])
{
	copy_int2char();
	compliant_copy_int2char();
	copy_int2uint();
	compliant_copy_int2uint();
	copy_long2char();
	compliant_copy_long2char();
	check_foo();
	return 0;
}
