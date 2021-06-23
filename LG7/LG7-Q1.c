//
//  main.c
//  LG7-1
//
//  Created by Asım Altınışık on 21.06.2021.
//

#include <stdio.h>

int
main ()
{
    
char sentence[100];
    
printf("Give a sentence: ", &sentence);
    
//scanf("%s", sentence);
        
//scanf("%[^\n]", sentence);

scanf("%[^0-9]", sentence);
    
printf("%s\n", sentence);
    
}
