#include <stdio.h>

int main()
{
	FILE *t;
	char buffer[BUFSIZ];

	/* create a temporary file */
	t = tmpfile();
	if( t==NULL )
	{
		perror("tmpfile()");
		return 1;
	}
	puts("File created");

	/* write a string */
	fprintf(t,"Hello, temporary file!\n");
	/* rewind file position to start */
	rewind(t);
	/* read in the string */
	fgets(buffer,BUFSIZ,t);
	printf("Read from file: %s",buffer);

	/* clean-up */
	fclose(t);		/* file is closed automatically at exit */
	return 0;
}
