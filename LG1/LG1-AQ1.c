//
//  main.c
//  LG1-AQ1
//
//  Created by Asım Altınışık on 19.06.2021.
//

#include <stdio.h>

void draw(int givenValue);

int
main()
{
    int givenValue;
    
    do {
        printf("Enter an integer (<=0 to stop):");
        scanf("%d", &givenValue);
        
        if (givenValue>0) {
            draw(givenValue);
        }
        
    } while (givenValue <= 0);
    return 0;
}

void
draw(int givenValue)
{
    for(int i = 1; i < givenValue * 2; i++)
        for (int j = givenValue - i; j >= 0; j--) {
            printf("*\n");
        }
        }
