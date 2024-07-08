#include <locale.h>
#include <wchar.h>

#define SAD 0x1f641
#define HAPPY 0x1f600
#define MEH 0x1f610
#define HUH 0x1f914

int main()
{
	wchar_t mood[3] = { SAD, HAPPY, MEH };
	wchar_t *moodstr[3] = { L"sad", L"happy", L"meh" };
	int x;
	wint_t m;

	setlocale(LC_ALL,"en_US.UTF-8");

	/* prompt for input */
	wprintf(L"What is your mood?\n");
	for(x=0;x<3;x++)
		wprintf(L"%d: %lc %ls\n",x+1,mood[x],moodstr[x]);
	wprintf(L"Choice: ");
	m = getwchar();

	/* output the choice */
	switch(m)
	{
		case '1':
			wprintf(L"%lc Sad\n",SAD);
			break;
		case '2':
			wprintf(L"%lc Happy\n",HAPPY);
			break;
		case '3':
			wprintf(L"%lc Meh\n",MEH);
			break;
		default:
			wprintf(L"%lc Huh?\n",HUH);
	}

	return 0;
}
