#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    printf("Type a letter: ");
    scanf("%c",&c);
    if( c > 'M' )
        abort();
    puts("That's a good letter");

    return 0;
}
