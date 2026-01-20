#include "game.h"

int main()
{
	int maxnum = 20;
	Game game(maxnum);
	game.play();
	game.printGameResult();
	return 0;
}
