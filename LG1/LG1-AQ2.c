//
//  main.c
//  LG1-AQ2
//
//  Created by Asım Altınışık on 19.06.2021.
//

#include <stdio.h>
#include <stdlib.h>

int readFromFile(FILE* inp, int idS[], int points[10][4]);

int
main()
{

    FILE* inp = ("tennis.txt", "r");
    if(inp==NULL)
        printf("File tennis.txt could not be opened.");
    else
    {
        int idS[10],
            points[10][4],
            numOfPlayers;
        
        numOfPlayers = readFromFile(inp, idS, points);
        printf("%d", idS[1]);
                
    }
    
    return 0;
}

int
readFromFile(FILE* inp, int idS[], int points[10][4])
{
    int i = 0;
    
    while (!feof(inp))
    {
        fscanf(inp, "%d", &idS[i]);
        fscanf(inp, "%d %d %d %d", &points[i][0], &points[i][1], &points[i][2], &points[i][3]);
        i++;
    }
    return i;
}
