#include <stdio.h>

int main()
{
	printf("'stdin' file number is %d\n",fileno(stdin));
	printf("'stdout' file number is %d\n", fileno(stdout));
	printf("'stderr' file number is %d\n", fileno(stderr));

	return(0);
}
