/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			initialize_variables.c			
=============================================================================*/ 
#include <stdio.h>

struct data {
	unsigned char age;
	char name[8];
};

void foo()
{
	struct data s_a;

	printf("%s() ", __FUNCTION__);
	printf("s_a.age: %d\n", s_a.age);
	printf("s_a.name: %s\n",s_a.name);		
}

void fill_stack(void)
{
	char buff[] = {25,'o','z','z','i',0, 0, 0, 0};

	printf("%s() ", __FUNCTION__);
}

int main(int argc, char *argv[])
{
	fill_stack();
	foo();	

	return 0;
}
