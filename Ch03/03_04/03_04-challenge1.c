#include <locale.h>
#include <wchar.h>

#define SAD 0x1f641
#define HAPPY 0x1f600
#define MEH 0x1f610
#define HUH 0x1f914

int main()
{
	// Emoji array: sad, happy, meh and confused
	wchar_t faces[4] = {0x2639, 0x1F60A, 0x1F610, 0x1F914};

	const int count = 32;
	wchar_t input[count];

	setlocale(LC_ALL, "en_US.UTF-8");

	// Display options
	wprintf(L"What is your mood?\n");
	wprintf(L"1:%lc sad\n", faces[0]);
	wprintf(L"2:%lc happy\n", faces[1]);
	wprintf(L"3:%lc meh\n", faces[2]);

	// Read in option
	int n;
	wscanf(L"%d", &n);

	switch (n)
	{
	case 1:
		wprintf(L"%lc Sad\n", faces[0]);
		break;

	case 2:
		wprintf(L"%lc Happy\n", faces[1]);
		break;

	case 3:
		wprintf(L"%lc Meh\n", faces[2]);
		break;

	default:
		wprintf(L"%lc Huh?\n", faces[3]);
		break;
	}

	return 0;
}
