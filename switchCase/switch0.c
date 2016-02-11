#include <stdio.h>

void playgame ()
{
	printf("Play game called.\n");
}
void loadgame ()
{
	printf("Load game called.\n");
}
void playmultiplayer ()
{
	printf("Play multiplayer game called.\n");
}

int main ()
{
	int input;

	printf("1. Play game\n");
	printf("2. Load game\n");
	printf("3. Play Multiplayer\n");
	printf("4. Exit\n");
	printf("Selection: ");
	scanf("%d", &input);
	switch (input) {
		case 1: 
			playgame();
			break;
		case 2:
			loadgame();
			break;
		case 3:
			playmultiplayer();
			break;
		case 4:
			printf("Thanks for playing.\n");
			break;
		default:
			printf("Bad input, quitting!\n");
			break;
	}
	getchar();
}
