#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define FD_READ 0
#define FD_WRITE 1

int main()
{
    const int size = 32;
    char buffer[size];
    int r,fd[2];
    const char *text = "I flow through the pipe";

    /* create the pipe */
    r = pipe(fd);
    if( r==-1 )
    {
        perror("Pipe");
        exit(1);
    }

    /* write to the pipe */
    r = write(fd[FD_WRITE], text, strlen(text)+1 );
    printf("Wrote '%s' (%d bytes) to fd %d\n",text,r,fd[FD_WRITE]);

    /* read from the pipe */
    r = read(fd[FD_READ], buffer, size );
    printf("Read '%s' (%d bytes) from fd %d\n",buffer,r,fd[FD_READ]);

    return(0);
}
