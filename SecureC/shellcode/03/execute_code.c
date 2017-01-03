/*============================================================================= 
#  Author:          Osvaldo Calles
#  Email:           osvaldo.calles@gmail.com 
#  Description:     
#  LastChange:      July 2017 
#  file:			execute_code.c	
=============================================================================*/

/*	 Compile: gcc -fno-stack-protector -z execstack execute_code.c -o execute_code 
	 Disable ASLR: echo 0 > /proc/sys/kernel/randomize_va_space           

	To exploit
 	$ cat in.txt | ./execute_code
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int global = 0;

void print_result(int a) {
	printf("result:%d\n", global * a);
	exit(0);
}


int suma(int a, int b) {
	global = a + b;
	system("/bin/sh");
	return 0;
}



int vuln() {
    char buf[80];
    int r;
    r = read(0, buf, 400);
    printf("\nRead %d bytes. buf is %s\n", r, buf);
    puts("No shell for you :(");
    return 0;
}

int main(int argc, char *argv[]) {
	int x = 10;
    printf("Try to exec /bin/sh\n");
	printf("var addr:%p\n", &x);
    vuln();
//	suma(3,4);
    return 0;
}
