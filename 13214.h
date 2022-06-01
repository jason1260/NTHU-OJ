#include <sstream>
#include <cstring>
#include <iostream>
using namespace std;

class Human {
public:
	string name;
	int money;
	int skill;
	int bets;
	int cards;

	Human(string n, int m, int ski);
	
	virtual void Pay(Human *human) {}
	virtual void Bet() {}
	void Draw();
	virtual int Win(Human *human) {}
	virtual bool Bankrupt() {}
	virtual bool Cheat(Human *human) {}
	virtual void Order(Human *banker, Human *server) {}
	
	~Human();
};
Human::Human(string n, int m, int ski) : name(n), money(m), skill(ski), bets(0), cards(0) {};
Human::~Human() {};
void Human::Draw() {
    this->cards = 0;
    string res = "";
    while (res.size() <= 0) getline(cin, res);
    stringstream ss(res);
    while (ss >> res) {
        int temp = 0;
        for (auto i : res)
            temp = temp * 10 + i - '0';
        this->cards += temp;
    }
}

class Guard : public virtual Human {
public:
	Guard(int ski);
	void Pay(Human *human);
};
Guard::Guard(int ski) : Human("guard", 0, ski) {};
void Guard::Pay(Human* human) {
	if (this->skill < human->skill) {
		this->money -= (human->skill - this->skill);
		human->money += (human->skill - this->skill);
	}
}

class Banker : public virtual Human {
public:
	Banker(int ski);
	void Pay(Human *human);
	int Win(Human *human);
	~Banker();
};
Banker::Banker(int ski) : Human("banker", 0, ski) {};
void Banker::Pay(Human* human) {
	if (human->name == "guard") {
		this->money -= 100;
		human->money += 100;
	}
	else {
		int bonus = (this->skill > human->skill) ? 10 * human->cards : 0;
		int total = (human->cards == 21) ? 2 * (human->bets + bonus) : human->bets + bonus;
		this->money -= total;
		human->money += total;
	}
}
int Banker::Win(Human* human) {

}
Banker::~Banker() {}

class Server : public virtual Human {
public:
	Server(int ski);
	~Server();
};
Server::Server(int ski) : Human("server", 0, ski) {};
Server::~Server() {}

class Player : public virtual Human {
public:
	Player(string name, int m, int ski);
	void Pay(Human *human);
	void Bet();
	bool Bankrupt();
	bool Cheat(Human *human);
	void Order(Human *banker, Human *server);
	~Player();
};
Player::Player(string name, int m, int ski) : Human(name, m, ski) {};
Player::~Player() {}
void Player::Pay(Human* human) {
	if (this->money <= this->bets) {
		human->money += this->money;
		this->money = 0;
	}
	else {
		human->money += this->bets;
		this->money -= this->bets;
	}
}
void Player::Bet() {
	int bt;
	cin >> bt;
	bets = bt;
}
bool Player::Bankrupt() {
	return this->money <= 0;
}
bool Player::Cheat(Human* human) {
	int bonus = (human->skill > this->skill) ? 10 * this->cards : 0;
	int total = (cards == 21) ? 2 * (bets + bonus) : bets + bonus;
	return 3 * this->skill < total;
}
void Player::Order(Human* banker, Human* server) {
	if (this->money <= 3000) return;
	this->money -= 3000;
	banker->money += 2000;
	server->money += 1000;
}

class Casino {
public:
	Casino();
	~Casino();
	void Enterance(int f, int u);
	void Guest(string s, int m, int ski);
	void TwentyOne();
	void EndDay();
	void Result();
	int fee, U;
	Human *banker, *guard, *server;
	int player_num;
	Human *player[1009];
	int total_income, today_income;
	int blacklist_num;
	string blacklist[100009];
};
Casino::Casino() : fee(0), U(0), player_num(0), total_income(0), today_income(0), blacklist_num(0) {
	for (int i = 0; i < 1009; i++) player[i] = NULL;
};
Casino::~Casino() {}
void Casino::Enterance(int f, int u) {fee = f; U = u;}
void Casino::Guest(string s, int m, int ski) {
	for (int i = 0; i < blacklist_num; i++) {
		if (blacklist[i] == s) return;
	}
	for (int i = 0; i < player_num; i++) {
		if (player[i]->name == s) return;
	}
	if (m <= fee) {
		blacklist[blacklist_num++] = s;
		return;
	}
	m -= fee;
	today_income += fee;
	player[player_num++] = new Player(s, m, ski);
} 
void Casino::TwentyOne() {
	int b, g, s, pn;
	cin >> b >> g >> s;
	banker = new Banker(b);
	guard = new Guard(g);
	server = new Server(s);
	cin >> pn;
	bool record[1009];
	bool kick[1009];
	for (int i = 0; i < 1009; i++) {record[i] = false; kick[i] = false;}
	for (int i = 0; i < pn; i++) {
		string name;
		cin >> name;
		bool flag = true;
		Player* new_player = new Player(name, 0, 0);
		new_player->Bet();
		new_player->Draw();
		for (int j = 0; j < blacklist_num; j++) {
			if (blacklist[j] == name) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int j = 0; j < player_num; j++) {
				if (player[j]->name == name) {
					record[j] = true;
					player[j]->bets = new_player->bets;
					player[j]->cards = new_player->cards;
				}
			}
		}
		delete new_player;
	}
	banker->Draw();
	for (int i = 0; i < player_num; i++) {
		if (record[i]) {
			if (player[i]->cards > 21 && banker->cards > 21) continue;
			else if (player[i]->cards <= 21 && (banker->cards > 21 || banker->cards < player[i]->cards)) { //Player Win
				banker->Pay(player[i]);
				if (player[i]->money > server->skill) player[i]->Order(banker, server);
				if (player[i]->Cheat(banker)) {
					//cout << player[i]->name << " is cheating.\n";
					banker->Pay(guard);
					guard->Pay(player[i]);
					kick[i] = true;
				}
			}
			else if (banker->cards <= 21 && (player[i]->cards > 21 || banker->cards >= player[i]->cards)) { //Player Lose
				player[i]->Pay(banker);
				if (player[i]->Bankrupt()) {
					//cout << player[i]->name << " is bankrupt.\n";
					banker->Pay(guard);
					kick[i] = true;
				}
			}
		}
	}
	cout << banker->money << ' ' << guard->money << ' ' << server->money << '\n';
	for (int i = 0; i < player_num; i++) {
		if (record[i]) {
			cout << player[i]->name << ' ' << player[i]->money << '\n';
		}
		if (kick[i]) {
			//cout << player[i]->name << " is kicked.\n";
			blacklist[blacklist_num++] = player[i]->name;
			Human* del = player[i];
			for (int j = i; j < player_num; j++) {player[j] = player[j + 1]; record[j] = record[j + 1]; kick[j] = kick[j + 1];}
			player_num--;
			delete del;
			i--;
		}
	}
	today_income += banker->money;
	delete banker;
	delete guard;
	delete server;
	banker = NULL;
	guard = NULL;
	server = NULL;
}
void Casino::EndDay() {
	for (int i = 0; i < player_num; i++) {
		delete player[i];
		player[i] = NULL;
	}
	player_num = 0;
	total_income += today_income;
	if (today_income >= U) {
		//cout << "Boss is happy.\n";
		for (int i = 0; i < blacklist_num; i++) {
			blacklist[i] = "";
		}
		blacklist_num = 0;
	}
	today_income = 0;
}
void Casino::Result() {
	cout << total_income << '\n';
	for (int i = 0; i < blacklist_num; i++) {
		cout << blacklist[i] << '\n';
	}
}