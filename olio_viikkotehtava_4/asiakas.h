#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <string>
#include "pankkitili.h"
#include "luottotili.h"

using namespace std;

class Asiakas
{
private:
	string nimi;
	Pankkitili kayttotili;
	Luottotili luottotili;

public:
	Asiakas(string, double);
	string getNimi();
	void showSaldo();
	bool talletus(double);
	bool nosto(double);
	bool luotonMaksu(double);
	bool luotonNosto(double);
	bool tiliSiirto(double, Asiakas& );
};

#endif // ASIAKAS_H
