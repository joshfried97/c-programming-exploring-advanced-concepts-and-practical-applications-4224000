#include <stdio.h>

int main()
{
    int r;

    r = rename("this.txt","that.txt");
    if( r == -1 )
    {
        fprintf(stderr,"File renaming error\n");
        return(1);
    }
    puts("File renamed");

    return(0);
}
