#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	/* template must end in six Xs */
	char template[] = "acXXXXXX";
	int fd;

	fd = mkstemp(template);		/* returns file descriptor */
	if( fd==-1 )
	{
		perror("msktemp()");
		return 1;
	}
	printf("Temporary file %s created\n",template);

	/* clean-up */
	close(fd);
	return 0;
}
