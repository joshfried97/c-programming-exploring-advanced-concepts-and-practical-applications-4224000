#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define FD_READ 0
#define FD_WRITE 1

void *patiently(void *p)
{
    int fd;
    char buffer[BUFSIZ];

    fd = *(int *)p;

	puts("THREAD> Waiting patiently...");
    read(fd,buffer,BUFSIZ);
    printf("THREAD> Received: %s",buffer);

    return(NULL);
}

int main()
{
    char buffer[BUFSIZ];
    int fp[2];
    pthread_t thd;
    int r;

    /* open the pipe */
    r = pipe(fp);
    if( r==-1 )
    {
        perror("Pipe");
        exit(1);
    }

    /* spawn the thread, passing it the read end of the pipe */
    r = pthread_create( &thd, NULL, patiently, (void *)&fp[FD_READ] );
    if( r!=0 )
    {
        perror("Thread");
        exit(1);
    }

    /* interact with the thread */
    printf("MAIN> Send some text to the thread: ");
    fgets(buffer,BUFSIZ,stdin);
    write(fp[FD_WRITE],buffer,strlen(buffer));

    puts("MAIN> Press Enter:");
    getchar();

    return(0);
}
