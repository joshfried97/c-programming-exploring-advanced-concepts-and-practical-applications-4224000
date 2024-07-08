#include <stdio.h>

int main()
{
	enum { TAB = '\t', NEWLINE = '\n' };

	for( int x=0; x<10; x++ )
		printf("%c%c%d%c",
				'A'+x,
				TAB,
				x,
				NEWLINE
			  );

	return 0;
}
