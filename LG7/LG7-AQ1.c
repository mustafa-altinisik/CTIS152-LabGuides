//
//  main.c
//  LG7-AQ1
//
//  Created by Asım Altınışık on 22.06.2021.
//

#include <stdio.h>
#include <string.h>

int main() {

    FILE* inp = fopen("input.txt", "r");
    if(inp == NULL)
        printf("File could not be opened.");
    else
    {
        int counts[10];
        char string[20];
        FILE* outp = fopen("output.txt", "w");
        
        for(int i = 0; i<10; i++)
        {
            counts[i] = 0;
        }
            
        
        while(!(feof(inp)))
        {
            fscanf(inp, "%s", string);
            
            for(int i = 0; i < 10; i++)
            {
            if(strlen(string) == i)
                counts[i]++;
            }
        }
        
        fprintf(outp, "Word Length\tOccurrences\n");
        fprintf(outp, "--------------------------\n");

        for(int i = 0; i<10; i++)
        {
            if(counts[i] != 0)
            {
                fprintf(outp, "     %d\t\t%d\n",i ,counts[i]);
            }
            
        }
        
    }
    return 0;
}
