#include "game.h"
#include "cstdlib"
#include <iostream>
#include <ctime>

using namespace std;

Game::Game(int maxnum)
{
	maxNumber = maxnum;
	numOfGuesses = 0;
	srand(time(NULL));
	randomNumber = 1 + (rand() % maxnum);
	cout << "GAME CONSTRUCTOR: object initialized with " << maxnum << " as a maximum value" << endl;
}

Game::~Game() {
	cout << "GAME DESTRUCTION: object cleared from stack memory" << endl;
}

void Game::play() {
	do {
		numOfGuesses++;
		cout << "Give your guess between 1-" << maxNumber << endl;
		cin >> playerGuess;
		if (playerGuess == randomNumber) {
			cout << "Your guess is right = " << playerGuess << endl;
		} else if (playerGuess < randomNumber ) {
			cout << "Your guess is too small" << endl;
		} else {
			cout << "Your guess is too big" << endl;
		}
	} while (playerGuess != randomNumber);
}
void Game::printGameResult() {
	cout << "You quessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << endl;
}
