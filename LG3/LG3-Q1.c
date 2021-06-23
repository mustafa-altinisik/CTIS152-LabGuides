#include <stdio.h>

int 
main(void)
{
	double matrix[4][3] = { { 34.25, 21.42, 65.78 },{ 81.52, 21.95, 20.12 },{ 21.96, 10.3, 50.17 },{ 40.47, 59.84, 35.26 } };

	printf("\n matrix : %p				Memory Location", matrix);
	printf("\n (matrix + 1) : %p			Memory Location", (matrix + 1));
	printf("\n *(matrix + 1) : %p			Memory Location", *(matrix + 1));
	printf("\n (*(matrix) + 1) : %p			Memory Location", (*(matrix)+1));
	printf("\n *(*(matrix) + 1) : %.3f			Value", *(*(matrix)+1));
	printf("\n *(*(matrix + 1)) : %.3f			Value", *(*(matrix + 1)));
	printf("\n *(*(matrix) + 1)+2 : %.3f			Value", *(*(matrix)+1) + 2);
	printf("\n (*(matrix + 1)+2) : %p			Memory Location", (*(matrix + 1) + 2));
	printf("\n *(*(matrix+1) + 2) : %.3f			Value\n", *(*(matrix + 1) + 2));
}
