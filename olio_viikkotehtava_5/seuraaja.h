#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>

using namespace std;

class Seuraaja
{
private:
    string nimi;
public:
    Seuraaja* next;

    Seuraaja(string);
    string getNimi();
    void paivitys(string);
};

#endif // SEURAAJA_H
