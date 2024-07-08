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

const char filename[] = "portfolio.dat";

/* open a saved database */
void open(void) {}

/* output the portfolio */
void list(struct stock *a)
{
	if( a==NULL )
	{
		puts("List empty!\n");
		return;
	}

	puts("List Portfolio");
	printf("%-8s%7s%10s%12s\n","Stock","Shares","Price","Value");
	while(a)
	{
		printf("%-8s%7d%10.2f%12.2f\n",
				a->symbol,
				a->quantity,
				a->price,
				a->quantity*a->price
			  );
		a = a->next;
	}
	putchar('\n');
}

/* create a new node/record */
struct stock *add(void)
{
	struct stock *a;

	/* allocate structure */
	a = malloc( sizeof(struct stock) );
	if( a==NULL )
	{
		fprintf(stderr,"Allocation error\n");
		exit(1);
	}

	/* fill structure data */
	printf("Stock symbol: ");
	scanf("%s",a->symbol);
	printf("Number of shares: ");
	scanf("%d",&a->quantity);
	printf("Price: ");
	scanf("%f",&a->price);
	a->next = NULL;		/* cap the list */

	puts("Node added\n");

	/* return the structure's address */
	return(a);
}

/* edit an existing node */
void edit(void) {}

/* remove a node */
void delete(void) {}

/* save the database */
void save(struct stock *a)
{
	FILE *fh;

	if( a==NULL )
	{
		puts("List empty!\n");
		return;
	}

	/* open the file */
	fh = fopen(filename,"w");	/* ok to overwrite */
	if( fh==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",filename);
		return;
	}

	/* write the records */
	while(a)
	{
		fwrite(a,sizeof(struct stock),1,fh);
		a = a->next;
	}

	/* close-up */
	fclose(fh);
	puts("Data written\n");
}

int main()
{
	struct stock *portfolio,*current;
	int done,c;

	portfolio = NULL;
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
				list(portfolio);
				break;
			case 3:
				if( portfolio==NULL )
				{
					portfolio = add();
				}
				else
				{
					current = portfolio;
					while(current->next)
						current = current->next;
					current->next = add();
				}
				break;
			case 4:
				edit();
				break;
			case 5:
				delete();
				break;
			case 6:
				save(portfolio);
				break;
			case 9:
				done = TRUE;
				break;
			default:
				puts("? Unknown command");
		}
	}

	/* clean-up */
	current = portfolio;
	while(current)
	{
		portfolio = current->next;
		free(current);
		current = portfolio;
	}
	return 0;
}
