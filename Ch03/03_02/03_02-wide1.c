#include <locale.h>
#include <wchar.h>

int main()
{
	wchar_t hello[4] = { 0x263a, 0x48, 0x69, 0x2665 };
	int x;

	/* first, set the locale */
    setlocale(LC_ALL,"en_US.UTF-8");

	/* output each wide character */
	for(x=0;x<4;x++)
		putwchar(hello[x]);
    putwchar('\n');

    return 0;
}
