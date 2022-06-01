#include <iostream>
#include <cstring>
#include "13450.h"
using namespace std;

Animal *animal[400000];

int main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	int num = 1;

	while ( q -- ) {
		string op;
		cin >> op;

		if (op == "Birth") {
			string name, species;
			cin >> name >> species;
			if (species == "cat")
				animal[num] = new Cat(name);
			else if (species == "fish")
				animal[num] = new Fish(name);
			else if (species == "bird")
				animal[num] = new Bird(name);
			else if (species == "human")
				animal[num] = new Human(name);
			num += 1;
		} else if (op == "Information") {
			int i;
			cin >> i;
			if (animal[i] != NULL)
				cout << animal[i]->get_name() << " " << animal[i]->get_species() << " " << animal[i]->get_HP() << "\n";
		} else if (op == "Talk") {
			int i; 
			cin >> i;
			if (animal[i] != NULL)
				animal[i]->Talk();

		} else if (op == "Breath") {
			int i, x;
			cin >> i >> x;
			if (animal[i] != NULL)
				animal[i]->Breath(x);
			
		} else if (op == "Sleep") {
			int i, x;
			cin >> i >> x;
			if (animal[i] != NULL)
				animal[i]->Sleep(x);

		} else if (op == "Work") {
			int i, x;
			cin >> i >> x;
			if (animal[i] != NULL) {
				animal[i]->Work(x);
				if (animal[i]->get_HP() <= 0) {
					delete animal[i];
					animal[i] = NULL;
				}
			}	

		} else if (op == "Eat") {
			int i, j;
			cin >> i >> j;
			if (animal[i] != NULL && animal[j] != NULL) {
				animal[i]->Eat(animal[j]);
				animal[j]->Eaten(animal[i]);
				if (animal[i]->get_HP() <= 0) {
					delete animal[i];
					animal[i] = NULL;
				}
				if (animal[j]->get_HP() <= 0) {
					delete animal[j];
					animal[j] = NULL;
				}	
			}
		}

	}
}
