#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"

class ItalianChef : public Chef
{
private:
	string password;
	int flour;
	int water;
	int makePizza();

public:
	ItalianChef(string);
	~ItalianChef();
	string getName();
	bool askSecret(string, int, int);
};

#endif // ITALIANCHEF_H
