#include "chef.h"
#include <cmath>
#include <iostream>

using namespace std;

Chef::Chef(string chefName)
{
	this->chefName = chefName;
	cout << this->getName() << " constructor" << endl;
}

Chef::~Chef() {
	cout << this->getName() << " deconstructor" << endl;
}

int Chef::makeSalad(int ingredientCount) {
	return floor(ingredientCount / 5);
}

int Chef::makeSoup(int ingredientCount) {
	return floor(ingredientCount / 3);
}

string Chef::getName() {
	return "Chef " + this->chefName;
}
