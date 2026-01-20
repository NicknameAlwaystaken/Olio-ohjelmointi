#ifndef GAME_H
#define GAME_H


class Game {
	int maxNumber;
	int playerGuess;
	int randomNumber;
	int numOfGuesses;

public:
	Game(int);
	~Game();
	void play();
	void printGameResult();
};

#endif // GAME_H
