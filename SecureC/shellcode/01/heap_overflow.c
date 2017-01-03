/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     Demonstrate you can overwrite two consecutives memory allocations
#  LastChange:      July 2017 
#  file:			heap_overflow.c	
=============================================================================*/ 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	use gdb to display all values in the heap
	gdb > info proc mappings
	
	gdb > break *address_of_line_33
	gdb > break *address_of_line_34
	gdb > break *address_of_line_40
	gdb > break *address_of_line_41
	gdb > break *address_of_line_45
 */

struct data {
	int type;
	char *info;
};


void get_root(void)
{
	printf("hacked\n");
}

int main(int arg, char *argv[])
{
	struct data *d1 = (struct data*) malloc(sizeof(struct data));
	d1->info = (char *)malloc(8);
	d1->type = 1;

	struct data *d2 = (struct data*) malloc(sizeof(struct data));
	d2->info = (char *)malloc(8);
	d2->type = 2;	

	strcpy(d1->info, argv[1]);
	strcpy(d2->info, argv[2]);

	printf("End of program\n");
	return 0;
}
