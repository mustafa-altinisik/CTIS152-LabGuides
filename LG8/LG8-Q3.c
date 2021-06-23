//
//  main.c
//  LG8-Q3
//
//  Created by Asım Altınışık on 23.06.2021.
//
#include <stdio.h>
#include <string.h>

int findAllOccur(char *sentence, char *given, int indexes[]);

int
main(void)
{
    char sentence[100], given[100];

    int    cnt, indexes[100];

    printf("\nEnter a sentence:");
    scanf("%[^\n]s", sentence);

    printf("\nEnter a string to display all occurances:");
    scanf("%s", given);

    //number of occurances = cnt
    cnt = findAllOccur(sentence, given, indexes);

    if (cnt == 0)
        printf("The sentence does NOT contain the string \"%s\"\n", given);
    else
    {
        printf("All %d occurences of the given \"%s\":\n",cnt, given);
        
        for (int i = 0; i < cnt; i++)
            printf("%3d", indexes[i]);

        printf("\n");
    }

    return(0);
}

int
findAllOccur(char *sentence, char *given, int indexes[])
{
    int    k,
        lengthSentence = strlen(sentence),
        lengthGiven = strlen(given),
        cnt = 0;

    for (k = 0; k <= lengthSentence - lengthGiven; k++)
    {

        if (strncmp(sentence + k, given, lengthGiven) == 0)
        {
            indexes[cnt] = k;
            cnt++;
        }
    }

    return(cnt);
}
