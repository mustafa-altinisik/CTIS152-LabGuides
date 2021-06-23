//
//  main.c
//  LG7-4
//
//  Created by Asım Altınışık on 22.06.2021.
//

#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    int wordcount = 0,
        status,
        i = 1;

    FILE *inp = fopen("history.txt", "r");
    if (inp == NULL)
        printf("The file does not exists!!");
    else
    {
        status = fscanf(inp, "%s", string);
//Lines
        while (status != EOF)
        {
//Words
            while (strcmp(string, "EOL") != 0)
            {
                wordcount++;
                status = fscanf(inp, "%s", &string);
            }
            printf("%d. line contains %d words\n", i, wordcount);
            i++;
            wordcount = 0;
            status = fscanf(inp, "%s", &string);
        }
    }
    fclose(inp);

    return 0;
}
