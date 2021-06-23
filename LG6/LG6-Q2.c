#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double averageScore,
            averageRebound;
} point_t;

typedef struct{
    char name[20];
    int age;
    double length;
    point_t points;
} player_t;

int readFromFile(FILE* inp, player_t* players);
void displayAll(player_t* players, int playerCount);
int findBestRebound(player_t* players, int playerCount);
double findAvgHeight(player_t* players, int playerCount);

int
main(){
    FILE* inp = fopen("players.txt", "r");

    if (inp == NULL)
        printf("Error! File counldn't be opened!\n");

    else{
        
        int playerCount, maxIndex;
        double avgHeight;
        
        player_t players[20];
        
        playerCount = readFromFile(inp, players);
        fclose(inp);
        
        displayAll(players, playerCount);
        avgHeight = findAvgHeight(players, playerCount);
        
        maxIndex = findBestRebound(players, playerCount);
        
        printf("\n\t\tThe Best rebound player:\n");
        printf("\t\tNAME\t\tAge     Length  Avg_Scr  Avg_Reb\n");
        printf("%15.15s \t %d \t %.2f \t %.2f \t %.2f \n", players[maxIndex].name, players[maxIndex].age, players[maxIndex].length, players[maxIndex].points.averageScore, players[maxIndex].points.averageRebound);
        
        printf("\n\t\tThe Avg Length of all players: %.2f\n\n", avgHeight);

    }
    

    
    return 0;
}

int
readFromFile(FILE* inp, player_t* players)
{
    int i = 0;

    while (!feof(inp)) {
        fscanf(inp, "%s %d %lf %lf %lf", players[i].name, &players[i].age, &players[i].length, &players[i].points.averageScore, &players[i].points.averageRebound);

        i++;
    }
    
    return i;
}

void
displayAll(player_t* players, int playerCount)
{
    printf("\t\tNAME\t\tAge     Length  Avg_Scr  Avg_Reb\n");
    printf("\t   ********************************************\n");
    
    for(int i = 0; i < playerCount; i++)
    {
        printf("%15.15s \t %d \t %.2f \t %.2f \t %.2f \n", players[i].name, players[i].age, players[i].length, players[i].points.averageScore, players[i].points.averageRebound);
    }
}

int
findBestRebound(player_t* players, int playerCount)
{
    int maxIndex = 0;
    
    for(int i = 1; i<playerCount; i++)
        if(players[i].points.averageRebound > players[maxIndex].points.averageRebound)
            maxIndex = i;
            
    return maxIndex;
}

double
findAvgHeight(player_t* players, int playerCount)
{
    double total = 0.0;
    
    for(int i = 0; i<playerCount; i++){
        total += players[i].length;
    }
    
    return total / playerCount;
}


