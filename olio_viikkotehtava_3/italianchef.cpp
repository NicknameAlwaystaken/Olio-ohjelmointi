#include "italianchef.h"
#include <cmath>
#include <iostream>

using namespace std;

ItalianChef::ItalianChef(string chefName) : Chef(chefName)
{
	password = "pizza";
	cout << this->getName() << " constructor" << endl;
}

ItalianChef::~ItalianChef() {
	cout << this->getName() << " deconstructor" << endl;
}

bool ItalianChef::askSecret(string givenPassword, int flour, int water) {
	if(givenPassword.compare(password) == 0) {
		cout << "Password ok!" << endl;
		this->flour = flour;
		this->water = water;
		int pizza_count = this->makePizza();

		cout << this->getName() << " with " << this->flour
				 << " flour and " << this->water
				 << " water can make " << pizza_count << " pizzas" <<endl;

		return true;
	}
	return false;
}

int ItalianChef::makePizza() {
	int flourCount = this->flour / 5;
	int waterCount = this->water / 5;
	int minCount = floor(flourCount < waterCount ? flourCount : waterCount);
	return minCount;
}

string ItalianChef::getName() {
	return "ItalianChef " + this->chefName;
}

