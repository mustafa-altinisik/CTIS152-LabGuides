#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct {
	char name[20];
	char type[20];
	double price;
	int releaseDate;
} game_t;

int
main() {
	game_t exGame;

	printf("Enter the information for the given game.");

	printf("Name :");
	scanf("%s", exGame.name);
	printf("Type :");
	scanf("%s", exGame.type);
	printf("Price :");
	scanf("%lf", &exGame.price);
	printf("Release date :");
	scanf("%d", &exGame.releaseDate);

	printf("The game information is below.\n");
	printf("Name of the game:	%s \n", exGame.name);
	printf("Type of the game:	%s \n", exGame.type);
	printf("Price of the game:	%.2f \n", exGame.price);
	printf("Price of the game:	%d \n", exGame.releaseDate);





	return 0;
}