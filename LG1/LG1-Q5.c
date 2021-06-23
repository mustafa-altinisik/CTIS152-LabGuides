//
//  main.c
//  LG1-Q5
//
//  Created by Asım Altınışık on 19.06.2021.
//

#include <stdio.h>
#include <stdlib.h>

void readFile(FILE* inp, int provinceCodes[], int temperature[4][5]);
void findHighestDegree(int temperature[4][5], int* highestRaw, int* highestColumn);
void findTotal(int temperature[4][5], int* total0, int* total1, int* total2, int* total3);

int
main()
{
    FILE *inp = fopen("Q5.txt", "r");
    if(inp==NULL)
        printf("File could not opened.");
    else
    {
        int provinceCodes[4],
            temperature[4][5];
        
        int highestRaw,
            highestColumn,
            highestYear;
        
        int total0=0,
            total1=0,
            total2=0,
            total3=0;
        
        readFile(inp, provinceCodes, temperature);
        findHighestDegree(temperature, &highestRaw, &highestColumn);
        
        printf("Average highest degree is: %d\n", temperature[highestRaw][highestColumn]);
        
        switch (highestColumn) {
            case 0:
                highestYear = 2016;
                break;
            case 1:
                highestYear = 2017;
                break;
            case 2:
                highestYear = 2018;
                break;
            case 3:
                highestYear = 2019;
                break;
            case 4:
                highestYear = 2020;
                break;
            
            default:
                break;
        }
        
        printf("Year: %d\n", highestYear);
        printf("City: %.2d\n", provinceCodes[highestRaw]);
        
        printf("\nCity\tTotal\n");
        
        findTotal(temperature, &total0, &total1, &total2, &total3);
            
        printf("%.2d\t\t%d\n", provinceCodes[0], total0);
        printf("%.2d\t\t%d\n", provinceCodes[1], total1);
        printf("%.2d\t\t%d\n", provinceCodes[2], total2);
        printf("%.2d\t\t%d\n", provinceCodes[3], total3);
        
        printf("\n");

        
    }
    return 0;
}

void
readFile(FILE* inp, int provinceCodes[], int temperature[4][5])
{
    int i = 0;
    
    while(!feof(inp))
    {
        fscanf(inp, "%d", &provinceCodes[i]);
        fscanf(inp, "%d %d %d %d %d", &temperature[i][0], &temperature[i][1], &temperature[i][2], &temperature[i][3], &temperature[i][4], &temperature[i][5]);
        
        i++;
    }
}

void
findHighestDegree(int temperature[4][5], int* highestRaw, int* highestColumn)
{
    int maxElement = temperature[0][0];
    
    for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 5; j++) {
             if (temperature[i][j] > maxElement) {
                 maxElement = temperature[i][j];
                 *highestRaw = i;
                 *highestColumn = j;
             }
         }
     }
}

void
findTotal(int temperature[4][5], int* total0, int* total1, int* total2, int* total3)
{
    for(int i=0; i<5; i++)
    {
        *total0 =  *total0 + temperature[0][i];
        *total1 =  *total1 + temperature[1][i];
        *total2 =  *total2 + temperature[2][i];
        *total3 =  *total3 + temperature[3][i];

    }
}
