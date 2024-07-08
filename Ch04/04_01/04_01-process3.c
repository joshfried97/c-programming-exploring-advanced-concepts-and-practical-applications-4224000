#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t process;

    process = getpid();
    printf("This program's process ID is %d\n",process);
	kill(process,SIGHUP);
	puts("Will you see this text?");

    return 0;
}
