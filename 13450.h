#include <iostream>
#include <cstring>
using namespace std;

class Animal {
	public:
		Animal();
		Animal(string n, string s);
		virtual ~Animal();
		
		virtual string get_name();
		virtual string get_species();
		virtual int get_HP();
		virtual void update_HP(int x);
		virtual void turn_HP_into_zero();
		
		virtual void Talk();
		virtual void Breath(int x);
		virtual void Sleep(int x);
		virtual void Work(int x);
		virtual void Eat(Animal *animal);
		virtual void Eaten(Animal *animal);
		
	private:
		string name;
		string species;
		int HP;
};
Animal::Animal() : name(""), species(""), HP(10) {};
Animal::~Animal() {}
Animal::Animal(string n, string s) : name(n), species(s), HP(10) {};
string Animal::get_name() {return name;}
string Animal::get_species() {return species;}
int Animal::get_HP() {return HP;}
void Animal::Talk() {}
void Animal::Eat(Animal* animal) {}
void Animal::Eaten(Animal* animal) {}
void Animal::update_HP(int x) {HP += x;}
void Animal::turn_HP_into_zero() {HP = 0;}
void Animal::Breath(int x) {HP += x;}
void Animal::Sleep(int x) {if (HP <= 100) HP *= x;}
void Animal::Work(int x) {HP -= x; if (HP <= 0) cout << name << " dead\n";}

class Cat : public virtual Animal {
	public:
		Cat(string n);
		virtual ~Cat();
		void Talk();
		void Eat(Animal *animal);
		void Eaten(Animal *animal);
};
Cat::Cat(string n) : Animal(n, "cat") {
	cout << n << " birth\n";
};
Cat::~Cat() {}
void Cat::Talk() {cout << "Meow\n";}
void Cat::Eat(Animal* animal) {
	if (animal->get_species() == "fish") {
		this->update_HP(animal->get_HP());
	}
}
void Cat::Eaten(Animal* animal) {
	if (animal->get_species() == "human") {animal->turn_HP_into_zero(); cout << animal->get_name() << " dead\n";}
}

class Fish : public virtual Animal {
	public:
		Fish(string n);
		virtual ~Fish();
		void Talk();
		void Eat(Animal *animal);
		void Eaten(Animal *animal);
};
Fish::Fish(string n) : Animal(n, "fish") {
	cout << n << " birth\n";
};
Fish::~Fish() {}
void Fish::Talk() {cout << "?\n";}
void Fish::Eat(Animal* animal) {}
void Fish::Eaten(Animal* animal) {
	if (animal->get_species() == "cat" || animal->get_species() == "bird" || animal->get_species() == "human") {
		this->turn_HP_into_zero();
		cout << this->get_name() << " dead\n";
	}
}

class Bird : public virtual Animal {
	public:
		Bird(string n);
		virtual ~Bird();
		void Talk();
		void Eat(Animal *animal);
		void Eaten(Animal *animal);
};
Bird::Bird(string n) : Animal(n, "bird") {
	cout << n << " birth\n";
};
Bird::~Bird() {}
void Bird::Talk() {cout << "Suba\n";}
void Bird::Eat(Animal* animal) {
	if (animal->get_species() == "fish") {
		this->update_HP(animal->get_HP());
	}
}
void Bird::Eaten(Animal* animal) {
	if (animal->get_species() == "human") {
		this->turn_HP_into_zero();
		cout << this->get_name() << " dead\n";
	}
}

class Human : public virtual Animal {
	public:
		Human(string n);
		virtual ~Human();
		void Talk();
		void Eat(Animal *animal);
};
Human::Human(string n) : Animal(n, "human") {
	cout << n << " birth\n";
};
Human::~Human() {}
void Human::Talk() {cout << "Hello, world\n";}
void Human::Eat(Animal* animal) {
	if (animal->get_species() == "bird" || animal->get_species() == "fish") {
		this->update_HP(animal->get_HP());	
	}
}