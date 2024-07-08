#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
	char symbol[8];
	int quantity;
	float price;
};

int main()
{
	struct stock *portfolio;

	/* allocate one stock structure */
	portfolio = malloc(sizeof(struct stock));
	if( portfolio==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* assign data */
	strcpy(portfolio->symbol,"MSFT");
	portfolio->quantity = 100;
	portfolio->price = 446.93;
	
	/* output the record */
	puts("Stock Portfolio");
	printf("%-8s%7s%10s%12s\n","Stock","Shares","Price","Value");
	printf("%-8s%7d%10.2f%12.2f\n",
			portfolio->symbol,
			portfolio->quantity,
			portfolio->price,
			portfolio->quantity*portfolio->price
		  );

	return 0;
}
