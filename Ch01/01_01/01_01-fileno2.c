#include <stdio.h>

int main()
{
	const char filename[] = "temp2";
	FILE *f;

	/* file opened without error checking */
	f = fopen(filename, "w");
	if (f == NULL)
	{
		fprintf(stderr, "Unable to open %s\n", filename);
		return 1;
	}

	printf("New file created, file number is %d\n", fileno(f));
	fclose(f);

	return 0;
}
