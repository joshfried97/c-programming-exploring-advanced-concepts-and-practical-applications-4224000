#include <locale.h>
#include <wchar.h>

int main()
{
    wchar_t direction[4] = {
        0x2190, 0x2191, 0x2192, 0x2193
    };
    wchar_t s;
    int x;

    setlocale(LC_ALL,"en_US.UTF-8");

    wprintf(L"Enter direction: ( ");
    for(x=0;x<4;x++)
        wprintf(L"%lc ",direction[x]);
    wprintf(L"): ");

    wscanf(L"%lc",&s);
    wprintf(L"Direction set to %lc\n",s);

    return(0);
}
