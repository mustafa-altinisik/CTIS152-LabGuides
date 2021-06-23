#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int readFile(FILE* inp, int ids[], double sales[]);
void display(int ids[], double sales[]);
void
findTotalMaxSales(int ids[], double sales[], int* staffOfDay, int* totalSale);

int
main(void)
{
	FILE* inp = fopen("staff.txt", "r");

	if (inp == NULL)
		printf("Error! File could not be opened!\n");
	else
	{
		int actualNoOfElems;
		int ids[SIZE];
		double sales[SIZE];
		int staffOfDay;
		double totalSale = 0.0;


		actualNoOfElems = readFile(inp, ids, sales);
		fclose(inp);

		display(ids, sales);

		findTotalMaxSales(ids, sales, &staffOfDay, &totalSale);

		printf("\nThe total sale is: %.2f TL \n", totalSale);
		printf("\nThe staff of the day : % d with sale : % .2f TL \n", ids[staffOfDay], sales[staffOfDay]);
	}
}


int
readFile(FILE* inp, int ids[], double sales[])
{
	int i = 0;

	while (fscanf(inp, "%d %lf ", &ids[i], &sales[i])!= EOF)
		i++;
	

	return i; //Sizes of arrays.

}

void
display(int ids[], double sales[])
{
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d \t %.2f \n", ids[i], sales[i]);
	}
}

void
findTotalMaxSales(int ids[], double sales[], int* staffOfDay, int* totalSale)
{
	int i = 0, max = 0;
	*totalSale = sales[i];

	for (i = 0; i < SIZE; i++) {

		if (sales[i] > sales[max])
			max = i;

		*totalSale += sales[i];

	}

	*staffOfDay = max;
}

