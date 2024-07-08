#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct stock {
	char symbol[8];
	int quantity;
	float price;
	struct stock *next;
};

/* open a saved database */
void open(void) {}

/* output the portfolio */
void list(void) {}

/* create a new node/record */
void add(void) {}

/* edit an existing node */
void edit(void) {}

/* remove a node */
void delete(void) {}

/* save the database */
void save(void) {}

int main()
{
	struct stock *portfolio,*current;
	int done,c;

	done = FALSE;
	while(!done)
	{
		/* output menu */
		puts("Stock Portfolio");
		puts("1. Open portfolio");
		puts("2. List portfolio");
		puts("3. Add stock");
		puts("4. Edit stock");
		puts("5. Delete stock");
		puts("6. Save portfolio");
		puts("9. Quit");
		printf("Choice: ");
		scanf("%d",&c);

		/* process input */
		switch(c)
		{
			case 1:
				open();
				break;
			case 2:
				list();
				break;
			case 3:
				add();
				break;
			case 4:
				edit();
				break;
			case 5:
				delete();
				break;
			case 6:
				save();
				break;
			case 9:
				done = TRUE;
				break;
			default:
				puts("? Unknown command");
		}
	}

	/* clean-up */
	return 0;
}
