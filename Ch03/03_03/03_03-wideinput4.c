#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main()
{
	const int count=32;
    wchar_t input[count];

    setlocale(LC_ALL,"en_US.UTF-8");

    wprintf(L"Type some fancy text: ");
	fgetws(input,count,stdin);
    wprintf(L"You typed: %ls\n",input);

    return 0;
}
