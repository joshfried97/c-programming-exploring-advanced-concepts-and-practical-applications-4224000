#include <stdio.h>
#include <errno.h>

int main()
{
    int r;

    r = rename("this.txt","that.txt");
    if( r == -1 )
    {
        fprintf(stderr,"File renaming error: ");
        switch(errno)
        {
            case EPERM:
                fprintf(stderr,"Operation not permitted\n");
                break;
            case ENOENT:
                fprintf(stderr,"File not found\n");
                break;
            case EACCES:
                fprintf(stderr,"Permission denied\n");
                break;
            case ENAMETOOLONG:
                fprintf(stderr,"Filename is too long\n");
                break;
            default:
                fprintf(stderr,"Unknown error\n");
        }
        return(1);
    }
    puts("File renamed");

    return(0);
}
