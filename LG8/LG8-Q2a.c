//
//  main.c
//  LG8-Q2a
//
//  Created by Asım Altınışık on 23.06.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirst(char *sentence, char *given);
void deleteFirst(char *sentene, char *given, int position);

int main()
{
    char sentence[100],
         given[30];
    
    printf("Enter a sentence:");
    scanf("%[^\n]s", sentence);

    printf("Enter a string to search:");
    scanf(" %s", given);

    int position = findFirst(sentence, given);
    
    if(position == -1)
        printf("Given string cannot be found in given sentence.");
    else
    {
        deleteFirst(sentence, given, position);
        printf("\nThe new form of the sentence after deletion:\n%s\n", sentence);

    }
    return 0;
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

void
deleteFirst(char *sentence, char *given, int position)
{
    int givenLength = strlen(given);
    char before[100] = "", after[100] = "";
    
    //Copying the part of the string before the given word.
    strncpy(before, sentence, position);
    //Copying the part of the string after the given word.
    strcpy(after, sentence + position + givenLength);
    
    strcpy(sentence, before);
    strcat(sentence, after);
    
}
