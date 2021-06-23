//
//  main.c
//  LG8-Q1b
//
//  Created by Asım Altınışık on 23.06.2021.
//

#include <stdio.h>
#include <string.h>

int findFirst(char *sentence, char *toBeSearched);
void replaceFirstOccur(char *sentence, char *toBeSearched, char *toBeReplaced, int pos);

int
main(void)
{
    char    sentence[100],
            toBeSearched[20],
            toBeReplaced[20];

    int    pos;

    printf("\nEnter a sentence:");
    scanf("%[^\n]s", sentence);

    printf("Enter a string to search:");
    scanf(" %s", toBeSearched);

    pos = findFirst(sentence, toBeSearched);

    if (pos == -1)
        printf("\nThe sentence does NOT contain the string \"%s\"\n", toBeSearched);
    
    //If given string's location is found
    else
    {
        printf("Enter a string to replace: ");
        scanf(" %s", toBeReplaced);

        replaceFirstOccur(sentence, toBeSearched, toBeReplaced, pos);
        
        //Sentence became new sentence after the replaceFirstOccur's call.
        printf("\nNew form of the sentence: \n%s ", sentence);

        printf("\n");
    }

    return(0);
}

int
findFirst(char *sentence, char *toBeSearched)
{
    int k,
        len1 = strlen(sentence),
        len2 = strlen(toBeSearched);

    for (k = 0; k <= len1 - len2; k++)
    {
        if (strncmp(sentence + k, toBeSearched, len2) == 0)
            return k;
    }
    //Return -1 if not found.
    return (-1);
}

void
replaceFirstOccur(char *sentence, char *toBeSearched, char *toBeReplaced, int pos)
{
    char    temp[100] = "";
    int    srchLen = strlen(toBeSearched);

    //Copying after part pf the sentence
    strcpy(temp, sentence + pos + srchLen);
    strcpy(sentence + pos, toBeReplaced);
    //concatenate beginning and after part of the word.(Upper two lines)
    strcat(sentence, temp);
}
