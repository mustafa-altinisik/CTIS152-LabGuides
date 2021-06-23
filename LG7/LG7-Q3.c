//
//  main.c
//  LG7-3
//
//  Created by Asım Altınışık on 21.06.2021.
//

#include <stdio.h>
#include <string.h>
int
main()
{
    char name[30];
    int given;
    int flag = 0;
    FILE* inp = fopen("names.txt", "r");
    
    
    if(inp == NULL)
        printf("File could not be opened.");
    else
    {
        printf("Enter the length of the name :");
        scanf("%d", &given);
        
        while (fscanf(inp, "%s", name) != EOF)
        {
            if(strlen(name) == given)
            {
                printf("%s\n", name);
                flag = 1;
            }

        }
        if(flag == 0 )
            printf("There is no name with the length %d.\n", given);


    }
}

