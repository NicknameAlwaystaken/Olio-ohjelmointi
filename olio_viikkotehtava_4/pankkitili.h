#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>

using namespace std;

class Pankkitili
{
protected:
	string omistaja;
	double saldo;

public:
	Pankkitili(string);
	double getBalance();
	virtual bool deposit(double);
	virtual bool withdraw(double);
};

#endif // PANKKITILI_H
