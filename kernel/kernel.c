#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) 
{
	terminal_initiaize();
	printf("This is Inferno v1.0\n");
}
