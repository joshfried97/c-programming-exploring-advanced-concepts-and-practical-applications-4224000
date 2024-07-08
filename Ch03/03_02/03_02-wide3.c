#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main()
{
	wchar_t hello[] = L"Hello, world!\n";

	/* first, set the locale */
    setlocale(LC_ALL,"en_US.UTF-8");

    fputws(hello,stdout);

    return 0;
}
