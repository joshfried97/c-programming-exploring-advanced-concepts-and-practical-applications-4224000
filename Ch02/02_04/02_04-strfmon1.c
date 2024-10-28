#include <stdio.h>
#include <locale.h>
#include <monetary.h>

int main()
{
    const int size = 32;
    char buffer[size];
    char *r;

    r = setlocale(LC_ALL, "en_US.UTF-8");
    if (r == NULL)
    {
        fprintf(stderr, "Unable to set locale\n");
        return (1);
    }

    // Must know the locale before running this function
    strfmon(buffer, size, "%n", 359246.80);
    puts(buffer);

    return (0);
}
