#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	double price;
	int discount;
} product_t;


int readFromFile(FILE* fp, product_t products[]);
void displayAllProducts(product_t products[], int count);

int
main() {
	int count;

	FILE* fp = fopen("n11.txt", "r");
	if (fp == NULL)
		printf("File n11.txt could not opened.");
	else
	{
		product_t products[10];

		count = readFromFile(fp, products);
		fclose(fp);
		displayAllProducts(products, count);
	}

	return 0;
}

int
readFromFile(FILE* fp, product_t products[])
{
	int count = 0;


	while (!feof(fp)) {

		fscanf(fp, "%s %lf %d", &products[count].name, &products[count].price, &products[count].discount);
		count++;
	}


	return(count);
}

void
displayAllProducts(product_t products[], int count)
{
	int i = 0;

	printf("\nThere are %d products in the market.\n", count);
	printf("\nPRODUCT NAME	PRICE		DISCOUNT	DISC. PRICE		SAVED AMOUNT\n");
	printf("************	*********	********	***********		************\n");

	for (i = 0; i < count; i++)
	{
		printf("%s\t%.2f\t%d\t%.2f\t%.2f\n", products[i].name, products[i].price, products[i].discount, (products[i].price-((products[i].price * products[i].discount) / 100)), (products[i].price- (products[i].price - ((products[i].price * products[i].discount) / 100))));
	}
	
}