#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	char template[] = "solution_XXXXXX";
	char newname[] = "solution1";
	int r;

	/* create a temporary file */
	puts("Creating a temporary file");
	r = mkstemp(template);
	if( r==-1 )
	{
		printf("errno = %d\n",errno);
		perror("File creation error");
	}
	printf("File '%s' created\n",template);

	/* rename it */
	printf("Renaming '%s' to '%s'\n",template,newname);
	r = rename(newname,template);
	if( r==-1 )
	{
		printf("errno = %d\n",errno);
		perror("Renaming error");
	}
	else
	{
		printf("File '%s' renamed to '%s'\n", template,newname);
	}

	/* delete it */
	printf("Deleting file '%s'\n",newname);
	r = unlink(newname);
	if( r==-1 )
	{
		printf("errno = %d\n",errno);
		perror("Deleting error");
	}
	else
	{
		printf("File '%s' deleted\n",newname);
	}

	return 0;
}
