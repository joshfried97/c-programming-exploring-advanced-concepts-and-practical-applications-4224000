#include <stdio.h>

int main()
{
    int r;

    r = rename("this.txt","that.txt");
    if( r == -1 )
    {
        perror("File renaming error");
        return(1);
    }
    puts("File renamed");

    return(0);
}
