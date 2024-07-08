#include <stdio.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

int main()
{
	printf("PATH_MAX is defined as %d\n",PATH_MAX);

	return 0;
}
