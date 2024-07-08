#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t process,parent;

    process = getpid();
	parent = getppid();
    printf("This program's process ID is %d\n",process);
    printf("This program's parent process ID is %d\n",parent);

    return(0);
}
