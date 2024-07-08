#include <stdio.h>

int main()
{
    const char normal[] = "stdout\n";
    const char error[] = "stderr ";

    fprintf(stdout,normal);
    fprintf(stderr,error);
    fprintf(stdout,normal);
    fprintf(stderr,error);
    fprintf(stdout,normal);
    fprintf(stderr,error);
	putchar('\n');

    return(0);
}
