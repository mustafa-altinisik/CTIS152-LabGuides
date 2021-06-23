//
//  main.c
//  LG7-2
//
//  Created by Asım Altınışık on 21.06.2021.
//

#include <stdio.h>

int myStrLen(char* cartoon);

int
main(void)
{
    FILE *inp, *outp;

    char cartoon[50];
    int len;

    inp = fopen("cartoon.txt", "r");

    if (inp == NULL)
        printf("\n Input file cannot be opened. \n");
    else
    {
        outp = fopen("result.txt", "w");

        while (fscanf(inp, "%s", cartoon) != EOF)
        {
            len = myStrLen(cartoon);
            fprintf(outp, "%s --> %d\n", cartoon, len);
        }

        fclose(inp);
        fclose(outp);
    }

    return(0);
}


int
myStrLen(char* cartoon)
{
    char* p = cartoon;

    while (*p != '\0')
        p++;

    //end - start point
    return (p - cartoon);
    
}
