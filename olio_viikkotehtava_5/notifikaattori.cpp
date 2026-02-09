#include "notifikaattori.h"
#include "iostream"

using namespace std;

Notifikaattori::Notifikaattori() {
    seuraajat = nullptr;
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja* uusi_seuraaja)
{
    if(!uusi_seuraaja) return;

    cout << "Notifikaattori lisaa seuraajan " << uusi_seuraaja->getNimi() << endl;
    uusi_seuraaja->next = this->seuraajat;
    this->seuraajat = uusi_seuraaja;
}

void Notifikaattori::poista(Seuraaja *poistettava_seuraaja)
{
    if(seuraajat == nullptr) return;
		if(poistettava_seuraaja == nullptr) return;

    Seuraaja* nykyinen = seuraajat;

    if(nykyinen == poistettava_seuraaja) {
        seuraajat = seuraajat->next;
        cout << "Notifikaattori poistaa seuraajan " << nykyinen->getNimi() << endl;
        return;
    } else {
        while(nykyinen->next != nullptr) {
            if(nykyinen->next == poistettava_seuraaja) {
                cout << "Notifikaattori poistaa seuraajan " << nykyinen->next->getNimi() << endl;
                nykyinen->next = poistettava_seuraaja->next;
                return;
            }
            nykyinen = nykyinen->next;
        }
    }
}

void Notifikaattori::tulosta()
{
    cout << "Notifikaattorin seuraajat:" << endl;

    Seuraaja* nykyinen = seuraajat;

    while(nykyinen != nullptr) {
        cout << "Seuraaja " << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    cout << "Notifikaattori postaa viestin " << viesti << endl;

    if(seuraajat == nullptr) return;

    Seuraaja* nykyinen = seuraajat;

    while(nykyinen != nullptr) {
        nykyinen->paivitys(viesti);

        nykyinen = nykyinen->next;
    }
}
