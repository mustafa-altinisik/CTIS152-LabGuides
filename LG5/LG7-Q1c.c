#include <stdio.h>

typedef struct {
	char name[20];
	char type[20];
	double price;
	int releaseDate;
} game_t;

int
main() {

	game_t exGame = { "Fortnite", "Action", 65, 2017 };
	
	game_t* ptr;
	ptr = &exGame;

	printf("The game information is below.\n");
	printf("Name of the game:	%s \n", ptr->name);
	printf("Type of the game:	%s \n", ptr->type);
	printf("Price of the game:	%.2f \n", ptr->price);
	printf("Price of the game:	%d \n", ptr->releaseDate);

	return 0;
}