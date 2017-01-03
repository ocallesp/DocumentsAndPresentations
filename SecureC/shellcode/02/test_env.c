#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	void (*function)(void);

    function = (void (*)(void))getenv("SHELLCODE");
    function();
    return 0;
}
