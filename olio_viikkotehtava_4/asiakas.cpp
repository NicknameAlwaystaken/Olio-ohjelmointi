#include "asiakas.h"
#include "pankkitili.h"
#include "luottotili.h"
#include <iostream>

using namespace std;

Asiakas::Asiakas(string nimi, double luottoraja)
	: kayttotili(nimi), luottotili(nimi, luottoraja)
{
	this->nimi = nimi;
	cout << "Pankkitili tehty " << this->getNimi() << ":lle" << endl;
	cout << "Uusi asiakas " << this->getNimi() << endl;
}

void Asiakas::showSaldo() {
	cout << "Kayttotili saldo: " << this->kayttotili.getBalance() << endl;
	cout << "Luottotili saldo: " << this->luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double amount) {
	bool success = kayttotili.deposit(amount);
	if(success) {
		cout << "Kayttotilin talletus " << amount << " tehty" << endl;
	}
	return success;
}

bool Asiakas::nosto(double amount) {
	bool success = kayttotili.withdraw(amount);
	if(success) {
		cout << "Kayttotilin nosto " << amount << " tehty" << endl;
	}
	return success;
}

bool Asiakas::luotonMaksu(double amount) {
	bool success = luottotili.deposit(amount);
	if(success) {
		cout << "Luoton maksu " << amount << " tehty" << endl;
	}
	return success;
}

bool Asiakas::luotonNosto(double amount) {
	bool success = luottotili.withdraw(amount);
	if(success) {
		cout << "Luoton nosto " << amount << " tehty" << endl;
	}
	return success;
}

bool Asiakas::tiliSiirto(double amount, Asiakas& customer) {
	cout << "Asiakas " << this->getNimi() << " siirtaa " << amount << " rahaa " << customer.getNimi() << ":lle " << endl;
	bool withdraw_successful = this->kayttotili.withdraw(amount);
	if(withdraw_successful) {
		bool deposit_successful = customer.kayttotili.deposit(amount);
		if(deposit_successful) {
			return true;
		}
		this->kayttotili.deposit(amount);
	}
	return false;
}

string Asiakas::getNimi() {
	return this->nimi;
}
