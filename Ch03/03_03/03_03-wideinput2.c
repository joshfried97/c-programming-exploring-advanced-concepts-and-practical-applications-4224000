#include <locale.h>
#include <wchar.h>

int main()
{
	const int count=10;
    wint_t input[count],wch;
	int x;

    setlocale(LC_ALL,"en_US.UTF-8");

    wprintf(L"Type some fancy text: ");

	/* read 'count' characters of input */
	x=0;
    while(x<count-1)
    {
        wch = getwchar();
        if( wch=='\n' || wch==WEOF )
            break;
        input[x] = wch;
        x++;
    }
    input[x] = '\0';

    wprintf(L"You typed: %ls\n",input);

    return 0;
}
