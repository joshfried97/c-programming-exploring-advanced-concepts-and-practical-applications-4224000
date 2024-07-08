#include <stdio.h>

int main()
{
	const char filename[] = "temp";
	FILE *f;

	/* file opened without error checking */
	f = fopen(filename,"w");
	printf("New file created, file number is %d\n",fileno(f));
	fclose(f);

	return 0;
}
