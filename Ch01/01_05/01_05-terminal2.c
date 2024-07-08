#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char *term;
	FILE *tout;

    term = ttyname(STDOUT_FILENO);
    printf("This is terminal %s\n",term);

	/* open the terminal as a file */
	tout = fopen(term,"w");
	if( tout==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",term);
		exit(1);
	}

	/* output text */
	fprintf(tout,"Hello to terminal %s\n",term);

	/* close-up */
	fclose(tout);
    return(0);
}
