#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    extern char **environ;

    while( *environ )
    {
        // This only ensures we print the strings associated with the PATH var
        if( strncmp(*environ,"PATH",4)==0 )
        {
            printf("%s\n",*environ);
            break;
        }
        environ++;
    }

    return 0;
}
