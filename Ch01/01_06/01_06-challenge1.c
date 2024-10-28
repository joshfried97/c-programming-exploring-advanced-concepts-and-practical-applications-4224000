#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
	int bc, x;

	/* seed the randomizer */
	srand((unsigned)time(NULL));

	// Create a buffer
	char buffer[BUFSIZ];

	// Change stdout to unbuffered
	setvbuf(stdout, buffer, _IONBF, BUFSIZ);

	bc = 0;
	for (x = 0; x < 20; x++)
	{
		printf("Writing %d bytes...\r", bc);
		bc += rand() % 32000;
		sleep(1);
	}
	putchar('\n');

	return 0;
}
