#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Search path:");
    // Much more efficient method for getting the PATH var
    printf("%s\n", getenv("PATH"));

    return 0;
}
