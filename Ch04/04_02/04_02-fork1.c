#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    printf("This code's PID is %d\n",getpid());

    return 0;
}
