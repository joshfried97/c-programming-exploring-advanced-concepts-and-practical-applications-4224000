#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char varstring[] = "language=C";
    const char newvar[] = "language";
    const char value[] = "C";

    printf("Setting variable '%s' to '%s'\n",
            newvar,
            value
          );
    putenv(varstring);

    printf("The '%s' variable equals '%s'\n",newvar,getenv(newvar) );

	printf("Removing variable '%s'...",newvar);
	unsetenv(newvar);
	printf("done\n");

    return 0;
}
