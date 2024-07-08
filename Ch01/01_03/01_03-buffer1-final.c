#include <stdio.h>

int main()
{
	char buffer[BUFSIZ];
	setvbuf(stdout,buffer,_IOFBF,BUFSIZ);

    puts("Hold it!");
    puts("Hold it!");
    puts("Go!");
    getchar();
    puts("Thank you.");

    return(0);
}
