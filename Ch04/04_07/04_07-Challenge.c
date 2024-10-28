#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define FD_READ 0
#define FD_WRITE 1

void *writeFunc(void *p)
{
  int fd;
  char buffer[] = "Hello from writing function!\n";

  fd = *(int *)p;

  write(fd, buffer, strlen(buffer) + 1);

  return (NULL);
}

void *readFunc(void *p)
{
  int fd;
  char buffer[BUFSIZ];

  fd = *(int *)p;

  puts("READ> Waiting patiently...");
  read(fd, buffer, BUFSIZ);
  printf("READ> Received: %s", buffer);

  return (NULL);
}

int main()
{
  char buffer[BUFSIZ];
  int fp[2];
  pthread_t thd1, thd2;
  int r1, r2;

  /* open the pipe */
  r1 = pipe(fp);
  if (r1 == -1)
  {
    perror("Pipe");
    exit(1);
  }

  /* spawn the thread, passing it the read end of the pipe */
  r1 = pthread_create(&thd1, NULL, writeFunc, (void *)&fp[FD_WRITE]);
  /* spawn the thread, passing it the write end of the pipe */
  r2 = pthread_create(&thd2, NULL, readFunc, (void *)&fp[FD_READ]);
  if (r1 != 0 || r2 != 0)
  {
    perror("Thread");
    exit(1);
  }
  getchar();

  return (0);
}
