#include <stdio.h>
#include <stdlib.h>

void all_done(void)
{
	puts("The task is complete");
}

int main()
{
	atexit(all_done);

	puts("I enjoy being a program");
	puts("And now I'm done");

	return 0;
}
