#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 2048

int main()
{
	const char filename[] = "sonnet18.txt";
	int fdes,x;
	char buffer[SIZE];
	size_t r;

	/* low-level open the file, read-only */
	fdes = open(filename,O_RDONLY);
	if( fdes==-1 )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	/* output file details */
	printf("File descriptor for %s is %d\n",filename,fdes);
	puts("File contents:\n");
	r = read( fdes,buffer,SIZE);
	for( x=0; x<r; x++ )
		putchar( buffer[x] );

	/* close-up */
	close(fdes);
	return 0;
}
