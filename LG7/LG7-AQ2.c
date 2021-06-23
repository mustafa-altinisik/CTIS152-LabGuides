//
//  main.c
//  LG7-AQ2
//
//  Created by Asım Altınışık on 22.06.2021.
//

#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    char description[100];
}activity_t;

int readFromFile(FILE* inp, activity_t activities[]);
void displayActivityList(activity_t activities[], int size);
int searchForActivity(activity_t activities[], int size, char given[]);
int searchForActivity(activity_t activities[], int size, char given[]);

int
main()
{
    FILE* inp = fopen("boredombusters.txt", "r");
    if(inp == NULL)
        printf("The input file could not be opened.");
    else
    {
        int size, ifFound;
        activity_t activities[20];
        size = readFromFile(inp, activities);
        printf("There are %d activities in the file.\n", size);
        displayActivityList(activities, size);
        
        char given[20];
        printf("\nWrite the full name of the activity that you prefer:");
        scanf("%[^\n]", given);
        
//        ifFound = searchForActivity(activities, size, given);
        
        if(searchForActivity(activities, size, given) == 0)
            printf("There is NO activity with the name %s \n", given);
        
    }

    return 0;
}

int
readFromFile(FILE* inp, activity_t activities[])
{
    int i = 0;
    while (!feof(inp))
    {
        fscanf(inp, "%[^:] %[^\n]", activities[i].name, activities[i].description);
        i++;
        
    }
    return i;
}

void
displayActivityList(activity_t activities[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%s", activities[i].name);
    }
}

int
searchForActivity(activity_t activities[], int size, char given[])
{
    int flag = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(strcmp(activities[i].name, given) == 0)
        
        {
            printf("Detailed information");
            printf("%s", activities[i].description);
            flag = 1;
        }

    }
    
        return flag;
        
}

