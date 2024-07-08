#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main()
{
	wchar_t hello[] = { 0x263a, 0x48, 0x69, 0x2665, '\n', '\0' };

	/* first, set the locale */
    setlocale(LC_ALL,"en_US.UTF-8");

    fputws(hello,stdout);

    return 0;
}
