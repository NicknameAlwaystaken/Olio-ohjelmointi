#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{
	Notifikaattori notifikaattori;

	Seuraaja a("A");
	Seuraaja b("B");
	Seuraaja c("C");

	notifikaattori.poista(&a);

	notifikaattori.lisaa(&a);
	notifikaattori.lisaa(&b);
	notifikaattori.lisaa(&c);
	notifikaattori.tulosta();

	notifikaattori.postita("Tama on viesti 1");

	notifikaattori.poista(&b);

	notifikaattori.postita("Tama on viesti 2");

	return 0;
}
