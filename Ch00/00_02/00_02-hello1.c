#include <locale.h>
#include <wchar.h>

int main()
{
	wchar_t world = 0x1F30E;

	/* set the locale */
	setlocale(LC_ALL,"en_US.UTF-8");
	/* output characters */
	wprintf(L"Hello, %lc\n",world);

	return 0;
}
