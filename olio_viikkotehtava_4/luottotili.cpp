#include "luottotili.h"
#include "pankkitili.h"
#include <iostream>

using namespace std;

Luottotili::Luottotili(string omistaja, double luottoraja)
	: Pankkitili(omistaja), luottoRaja(luottoraja)
	// luottoRaja(luottoraja) alustaa luottoRaja arvon luottoraja arvolla
	// ennenkuin constructori ajautuu
{
	this->saldo = luottoraja;
	cout << "Luottotili tehty " << this->omistaja << ":lle" << endl;
}

bool Luottotili::deposit(double amount) {
	if(amount <= 0) {
			cout << "Talletuksen maara ei voi olla 0 tai alle." << endl;
		return false;
	}

	double current_saldo = this->getBalance();

	if(amount + current_saldo <= 0) {
		this->saldo = this->getBalance() + amount;
		cout << "Talletus onnistui. Saldo: " << this->getBalance() << endl;
		return true;
	}

	cout << "Talletus menee yli 0 saldon. Saldo: " << this->getBalance() << endl;
	return false;
}

bool Luottotili::withdraw(double amount) {
	if(amount <= 0) {
		cout << "Noston maara ei voi olla 0 tai alle." << endl;
		return false;
	}

	double current_saldo = this->getBalance();
	double allowed_debt = -luottoRaja;

	if(current_saldo - amount >= allowed_debt) {
		this->saldo = current_saldo - amount;
		cout << "Nosto onnistui. Saldoa jaljella: " << this->getBalance() << endl;
		return true;
	}
	cout << "Luottoraja tuli vastaan. Saldo: " << this->getBalance()
			 << " Luottoraja: " << this->luottoRaja << endl;
	return false;
}
