#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct stock
{
	char symbol[8];
	int quantity;
	float price;
	struct stock *next;
};

int modified = FALSE;

const char filename[] = "portfolio.dat";

/* open a saved database */
struct stock *open(void)
{
	struct stock *base, *current;
	FILE *fh;
	int count = 0;

	base = NULL; /* initialize */
	/* open the file - if it exists */
	fh = fopen(filename, "r");
	if (fh == NULL)
	{
		fprintf(stderr, "Unable to open %s\n\n", filename);
		return (NULL);
	}

	/* read in the records */
	while (!feof(fh))
	{
		/* first record */
		if (base == NULL)
		{
			base = malloc(sizeof(struct stock));
			current = base;
			if (base == NULL)
			{
				fprintf(stderr, "Unable to allocate memory\n");
				exit(1);
			}
			/* deal with an empty file */
			if (fread(base, sizeof(struct stock), 1, fh) == 0)
			{
				printf("File %s is empty\n", filename);
				free(base);
				return (NULL);
			}
			count++;
		}
		else /* all other records */
		{
			/* leave if this is the last record */
			if (current->next == NULL)
				break;
			current->next = malloc(sizeof(struct stock));
			if (current->next == NULL)
			{
				fprintf(stderr, "Unable to allocate memory\n");
				exit(1);
			}
			fread(current->next, sizeof(struct stock), 1, fh);
			current = current->next;
			count++;
		}
	}

	/* clean-up */
	printf("%d records read\n\n", count);
	fclose(fh);
	return (base);
}

/* output the portfolio */
void list(struct stock *a)
{
	if (a == NULL)
	{
		puts("List empty!\n");
		return;
	}

	puts("List Portfolio");
	printf("%-8s%7s%10s%12s\n", "Stock", "Shares", "Price", "Value");
	while (a)
	{
		printf("%-8s%7d%10.2f%12.2f\n",
					 a->symbol,
					 a->quantity,
					 a->price,
					 a->quantity * a->price);
		a = a->next;
	}
	putchar('\n');
}

/* create a new node/record */
struct stock *add(void)
{
	struct stock *a;

	/* allocate structure */
	a = malloc(sizeof(struct stock));
	if (a == NULL)
	{
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}

	/* fill structure data */
	printf("Stock symbol: ");
	scanf("%s", a->symbol);
	printf("Number of shares: ");
	scanf("%d", &a->quantity);
	printf("Price: ");
	scanf("%f", &a->price);
	a->next = NULL; /* cap the list */

	puts("Node added\n");

	modified = TRUE;

	/* return the structure's address */
	return (a);
}

/* edit an existing node */
struct stock *edit(struct stock *a)
{
	char s[8];
	struct stock *base;

	/* check for empty list */
	if (a == NULL)
	{
		puts("List empty!\n");
		return (a);
	}

	/* initialize pointers */
	base = a;

	/* prompt for the symbol to edit */
	list(a);
	printf("Symbol to edit: ");
	scanf("%s", s);

	while (a)
	{
		char t[8];
		if (strcmp(a->symbol, s) == 0)
		{
			printf("%-8s%7d%10.2f%12.2f\n",
						 a->symbol,
						 a->quantity,
						 a->price,
						 a->quantity * a->price);
			printf("Edit (Y/N)? ");
			scanf("%s", t); /* re-use s here */
			if (t[0] == 'y' || t[0] == 'Y')
			{
				/* output menu */
				int n;
				puts("Select element to edit");
				puts("1. Symbol");
				puts("2. Quantity");
				puts("3. Price");
				printf("Choice: ");
				scanf("%d", &n);

				switch (n)
				{
				case 1:
					printf("Enter new symbol (4 letters max): ");
					scanf("%s", &a->symbol);
					break;

				case 2:
					printf("Enter new quantity: ");
					scanf("%d", &a->quantity);
					break;

				case 3:
					printf("Enter new price: ");
					scanf("%f", &a->price);
					break;

				default:
					printf("Invalid option");
					break;
				}

				// Display new data
				puts("Updated recored: ");
				printf("%-8s%7d%10.2f%12.2f\n",
							 a->symbol,
							 a->quantity,
							 a->price,
							 a->quantity * a->price);
				printf("Save (Y/N)? ");
				scanf("%s", t); /* re-use s here */
				if (t[0] == 'y' || t[0] == 'Y')
				{
					save(a);
					modified = TRUE;
				}
				else
				{
					puts("Record not saved\n");
				}
				
				return (base);
			}
			else /* keep the record */
			{
				puts("Record not edited\n");
				return (base);
			}
		}
		a = a->next;
	}
	printf("Stock symbol '%s' not found\n\n", s);
	return (base);
}

/* remove a node */
struct stock *delete(struct stock *a)
{
	char s[8];
	struct stock *base, *previous;

	/* check for empty list */
	if (a == NULL)
	{
		puts("List empty!\n");
		return (a);
	}

	/* initialize pointers */
	base = previous = a;

	/* prompt for the symbol to remove */
	list(a);
	printf("Symbol to remove: ");
	scanf("%s", s);

	while (a)
	{
		if (strcmp(a->symbol, s) == 0)
		{
			printf("%-8s%7d%10.2f%12.2f\n",
						 a->symbol,
						 a->quantity,
						 a->price,
						 a->quantity * a->price);
			printf("Delete (Y/N)? ");
			scanf("%s", s); /* re-use s here */
			if (s[0] == 'y' || s[0] == 'Y')
			{
				/* check for the first record */
				if (a == base)
				{
					base = a->next; /* reset base to 2nd record */
					free(a);				/* remove first record */
					puts("Record deleted\n");
					modified = TRUE;
					return (base);
				}
				else
				{
					previous->next = a->next;
					free(a);
					puts("Record deleted\n");
					return (base);
				}
			}
			else /* keep the record */
			{
				puts("Record retained\n");
				return (base);
			}
		}
		previous = a;
		a = a->next;
	}
	printf("Stock symbol '%s' not found\n\n", s);
	return (base);
}

/* save the database */
void save(struct stock *a)
{
	FILE *fh;

	if (a == NULL)
	{
		puts("List empty!\n");
		return;
	}

	/* open the file */
	fh = fopen(filename, "w"); /* ok to overwrite */
	if (fh == NULL)
	{
		fprintf(stderr, "Unable to create %s\n", filename);
		return;
	}

	/* write the records */
	while (a)
	{
		fwrite(a, sizeof(struct stock), 1, fh);
		a = a->next;
	}

	/* close-up */
	fclose(fh);
	puts("Data written\n");
}

int main()
{
	struct stock *portfolio, *current;
	char s[8];
	int done, c;

	portfolio = NULL;
	done = FALSE;

	while (!done)
	{
		/* output menu */
		if (modified)
		{
			printf("A change has been detected. Would you like to save (Y/N)?");
			scanf("%s", s); /* re-use s here */
			if (s[0] == 'y' || s[0] == 'Y')
			{
				save(portfolio);
				modified = FALSE;
			}
		}

		puts("Stock Portfolio");
		puts("1. Open portfolio");
		puts("2. List portfolio");
		puts("3. Add stock");
		puts("4. Edit stock");
		puts("5. Delete stock");
		puts("6. Save portfolio");
		puts("9. Quit");
		printf("Choice: ");
		scanf("%d", &c);

		/* process input */
		switch (c)
		{
		case 1:
			portfolio = open();
			break;
		case 2:
			list(portfolio);
			break;
		case 3:
			if (portfolio == NULL)
			{
				portfolio = add();
			}
			else
			{
				current = portfolio;
				while (current->next)
					current = current->next;
				current->next = add();
			}
			break;
		case 4:
			portfolio = edit(portfolio);
			break;
		case 5:
			portfolio = delete (portfolio);
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
	while (current)
	{
		portfolio = current->next;
		free(current);
		current = portfolio;
	}
	return 0;
}
