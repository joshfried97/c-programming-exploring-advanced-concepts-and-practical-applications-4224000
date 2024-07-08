#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define FD_READ 0
#define FD_WRITE 1

/* writing thread */
void *thread1(void *p)
{
    int fd;
    char message[] = "Greetings from Thread 1!\n";

    fd = *(int *)p;

	write(fd,message,strlen(message)+1);

    return(NULL);
}
/* reading thread */
void *thread2(void *p)
{
    int fd;
    char buffer[BUFSIZ];

    fd = *(int *)p;

    read(fd,buffer,BUFSIZ);
    printf("Thread 2 received: %s",buffer);

    return(NULL);
}

int main()
{
    int fp[2];
    pthread_t thd;
    int p,r1,r2;

    /* create a pipe */
    p = pipe(fp);
    if( p==-1 )
    {
        perror("Pipe");
        exit(1);
    }

    /* spawn the first thread and the read end of the pipe */
    r1 = pthread_create( &thd, NULL, thread1, (void *)&fp[FD_WRITE] );
    /* spawn the second thread and the write end of the pipe */
    r2 = pthread_create( &thd, NULL, thread2, (void *)&fp[FD_READ] );
    if( r1!=0 || r2!=0 )
    {
        perror("Thread");
        exit(1);
    }

    /* wait here */
    getchar();

    return(0);
}
