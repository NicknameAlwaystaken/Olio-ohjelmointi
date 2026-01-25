#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
	Chef gordon("Gordon");
	int salad_ingredients = 11;
	int soup_ingredients = 14;

	int salad_count = gordon.makeSalad(salad_ingredients);
	int soup_count = gordon.makeSoup(soup_ingredients);

	cout << gordon.getName() << " with " << salad_ingredients
			 << " items can make salad " << salad_count << " portions" << endl;

	cout << gordon.getName() << " with " << soup_ingredients
			 << " items can make soup " << soup_count << " portions" << endl;

	cout << endl;

	ItalianChef mario("Mario");
	salad_ingredients = 9;
	int pizza_water = 12;
	int pizza_flour = 12;

	salad_count = mario.makeSalad(salad_ingredients);

	cout << mario.getName() << " with " << salad_ingredients
			 << " items can make salad " << salad_count << " portions" <<endl;

	string password_text = "pizza";
	bool sercret_correct = mario.askSecret(password_text, pizza_flour, pizza_water);

	return 0;
}
