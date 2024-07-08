#include <stdio.h>
#include <locale.h>
#include <monetary.h>

int main()
{
	const int size=32;
    char buffer[size];
    char *r;

    r = setlocale(LC_ALL,"fr_FR.UTF-8");
    if( r==NULL )
    {
        fprintf(stderr,"Unable to set locale\n");
        return(1);
    }

    strfmon(buffer,size,"%n",123456.78);
    puts(buffer);

    return(0);
}
