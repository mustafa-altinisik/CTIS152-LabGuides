//
//  main.c
//  LG8-Q1a
//
//  Created by Asım Altınışık on 22.06.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findFirst(char *sentence, char *given);

int
main(void)
{
    char sentence[100], given[20];
    int pos;

    printf("Enter a sentence: ");
    scanf("%[^\n]s", sentence);

    printf("\nEnter a string to search: ");
    scanf("%s", given);

    pos = findFirst(sentence, given);

    if (pos == -1)
        printf("Could not find the given string \"%s\"\n", given);
    else
        printf("The first occurence of the str \"%s\" is %d\n", given, pos);

    return(0);
}

int
findFirst(char *sentence, char *given)
{
    int k,
        lengthSentence = strlen(sentence),
        lenGiven = strlen(given);

    for (k = 0; k <= lengthSentence - lenGiven; k++)
    {
        if (strncmp(sentence + k, given, lenGiven) == 0)
            return k;
    }
    return (-1);
}
