#include <iostream>
#include <cstdlib>

using namespace std;

int game(int);

int main()
{
	/*
Arvotaan satunnainen luku
Kysytään pelaajalta arvaus
Tarkistetaan onko arvaus pienempi, suurempi tai yhtäsuuri kuin luku
Kerrotaan tarkistuksen tulos tyyliin ”luku on pienempi/suurempi” tai ”oikea vastaus”
Jos pelaajan vastaus ei ollut oikein, niin palataan kohtaan 2.
*/
	srand(time(NULL));
	int maxnum;
	cout << "Hello World!" << endl;
	cout << "Anna maxnum: ";
	cin >> maxnum;
	int guesses = game(maxnum);
	cout << "Arvauksia meni: " << guesses;
	return 0;
}

int game(int maxnum) {
	int guesses = 0;
	int correct_answer = 1 + (rand() % maxnum);
	int guess_input;
	while(1) {
			guesses++;
			cout << "Arvaa luku: ";
			cin >> guess_input;
			if (guess_input == correct_answer) {
				cout << "Oikein meni!" << endl;
				break;
			} else if (guess_input < correct_answer) {
				cout << "Arvasit liian pienen numeron" << endl;
			} else {
				cout << "Arvasit liian korkean numeron" << endl;
			}
	}

	return guesses;
}
