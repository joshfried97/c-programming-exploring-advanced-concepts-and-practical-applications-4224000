#include <stdio.h>

int main()
{
	const int size = 64;
	char name[size];

	printf("Your name: ");
	fgets(name,size,stdin);
	printf("Pleased to meet you, %s",name);

	return 0;
}
