/* Compile: gcc -fno-stack-protector -z execstack classic.c -o classic */
/* Disable ASLR: echo 0 > /proc/sys/kernel/randomize_va_space           */ 

#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>

__attribute__((constructor))
void antidegugger(void) 
{
	printf("Constructor\n");
	ptrace(PTRACE_TRACEME);
}

__attribute__((destructor))
void removeantidegugger(void) 
{
	printf("destructor\n");
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
    printf("Try to exec /bin/sh");
    vuln();
    return 0;
}
