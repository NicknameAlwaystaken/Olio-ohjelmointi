#include "pankkitili.h"
#include <iostream>

using namespace std;

Pankkitili::Pankkitili(string omistaja)
{
	this->omistaja = omistaja;
	this->saldo = 0;
}

bool Pankkitili::deposit(double amount) {
	if(amount > 0) {
		saldo = this->getBalance() + amount;
		cout << "Talletus onnistui. Saldo: " << this->getBalance() << endl;
		return true;
	}

	cout << "Talletuksen maara ei voi olla 0 tai alle." << endl;
	return false;
}

bool Pankkitili::withdraw(double amount) {
	if(amount <= 0) {
		cout << "Noston maara ei voi olla 0 tai alle." << endl;
		return false;
	}

	double current_saldo = this->getBalance();
	if(amount <= current_saldo) {
		saldo = current_saldo - amount;
		cout << "Nosto onnistui. Saldoa jaljella: " << this->getBalance() << endl;
		return true;
	}
	cout << "Ei ollut tarpeeksi saldoa. Saldoa jaljella: " << this->getBalance() << endl;
	return false;
}

double Pankkitili::getBalance() {
	return this->saldo;
}
