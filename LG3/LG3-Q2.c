#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int 
main(void)
{
	//Result file pointer initialization.
	FILE* fp = fopen("result.txt", "w");;

	int	arr[4][4], 
		//Multiplier variable
		n = 1;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			//Multiplies variable with four after each operation.
			n *= 4;
			*(*(arr + i) + j) = n;
		}

	fprintf(fp, "   Element Name		Value	 Address\n", ' ');
	fprintf(fp, "------------------	-----	 --------\n", ' ');

	//Wriring matrix information into file "result.txt" .
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			fprintf(fp, "*(*(arr + %3d) + %3d)   %8d   %p\n", i, j, *(*(arr + i) + j), *(arr + i) + j);

	fclose(fp);

	if (fp != NULL)
		printf("Succesfully writed into output file \"result.txt\".\n\n");
}