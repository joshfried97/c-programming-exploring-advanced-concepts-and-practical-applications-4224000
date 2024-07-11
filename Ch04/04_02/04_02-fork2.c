#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t process;

    process = fork();
	/* program is split here */
	if( process==0 )
	{
		printf("Child: fork() returned %d\n",process);
		printf("Child: This is the child process, PID %d\n",getpid());
	}
	else
	{
		printf("Parent: fork() returned %d\n",process);
		printf("Parent: This is the parent process, PID %d\n",getpid());
	}

    return 0;
}
