//
//  main.c
//  LG1-Q4
//
//  Created by Asım Altınışık on 19.06.2021.
//

#include <stdio.h>

int findMaxFreq(int frequency[]);

int main()
{
    FILE* inp = fopen("votes.txt", "r");
    if(inp==NULL)
        printf("The file could not be opened.");
    else
    {
        int scanned;
        int frequency[5];
        
        while(!(feof(inp)))
        {
            fscanf(inp, "%d",&scanned);
           
            switch (scanned) {
                case 1:
                    frequency[0]++;
                    break;
                case 2:
                    frequency[1]++;
                    break;
                case 3:
                    frequency[2]++;
                    break;
                case 4:
                    frequency[3]++;
                    break;
                case 5:
                    frequency[4]++;
                    break;
                    
                default:
                    break;
            }
        }
        
        int maxIndex = findMaxFreq(frequency);
        
        printf("Competitor\tFrequency\n");
        
        printf("1\t\t%d\n", frequency[0]);
        printf("2\t\t%d\n", frequency[1]);
        printf("3\t\t%d\n", frequency[2]);
        printf("4\t\t%d\n", frequency[3]);
        printf("5\t\t%d\n", frequency[4]);
        
        //Array index starts from 0 while array's starts from 1 so I added 1 to array index.
        printf("\nThe winner is %d. competitor.\n\n", maxIndex+1);
        
    }
}

int
findMaxFreq(int frequency[])
{
    int maxIndex = 0;
    
    for(int i = 0; i < 5; i++)
        if(frequency[i] > frequency[maxIndex])
            maxIndex = i;
    
    return maxIndex;
}
