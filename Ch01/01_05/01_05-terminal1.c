#include <stdio.h>
#include <unistd.h>

int main()
{
    char *term;

    term = ttyname(STDOUT_FILENO);
    printf("This is terminal %s\n",term);

    return(0);
}
