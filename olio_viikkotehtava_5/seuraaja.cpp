#include "seuraaja.h"
#include "iostream"

using namespace std;

Seuraaja::Seuraaja(string nimi) : nimi(nimi)
{
    this->next = nullptr;
    cout << "Luodaan seuraaja " << this->getNimi() << endl;
}

string Seuraaja::getNimi()
{
    return this->nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout << "Seuraaja " << this->getNimi() << " sai viestin " << viesti << endl;
}


