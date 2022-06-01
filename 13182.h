#include <string>
#include <iostream>
using namespace std;

class Guest {
public:
	Guest();
	Guest(string s, int m, int ski);
	~Guest();
	string get_name();
	int get_money();
	int get_skill();
	void Win(int m);
	
private:
	string name;
	int money;
	int skill;
};

Guest::Guest() : money(0), skill(0), name("") {};
Guest::~Guest() {};
Guest::Guest(string s, int m, int ski) : name(s), money(m), skill(ski) {};
string Guest::get_name() {return name;}
int Guest::get_money() {return money;}
int Guest::get_skill() {return skill;}
void Guest::Win(int m) {
	money = ((m + money) > 0) ? money + m : 0;
}

class Casino {
public:
	Casino();
	~Casino();
	void Enterance(int f);
	void GuestEnter(string s, int m, int ski);
	void Win(string s, int m);
	void EndDay();
	void Result();
	
private:
	int fee;
	int guest_num;
	Guest *guest[1009];
	int income;
	int list_num;
	string blacklist[1009];
};

Casino::Casino() : fee(0), guest_num(0), income(0), list_num(0) {};
Casino::~Casino() {};
void Casino::Enterance(int f) {fee = f;}
void Casino::GuestEnter(string s, int m, int ski) {
	for (int i = 0; i < 1009; i++) {
		if (blacklist[i] == s) return;
		if (guest[i] && guest[i]->get_name() == s) return;
	}
	if (m - fee <= 0) {
		for (int j = 0; j < 1009; j++) if (blacklist[j] == "") {blacklist[j] = s; break;}
		income += m;
		return;
	}
	for (int i = 0; i < 1009; i++) {
		if (!guest[i]) {
			guest[i] = new Guest(s, m - fee, ski);
			guest_num++;
			//cout << "Curent income: " << income << '\n';
			income += fee;
			break;
		}
	}
}
void Casino::Win(string s, int m) {
	if (m == 0) return;
	int flag = 0, cnt = 0;
	for (int i = 0; i < 1009; i++) {
		if (blacklist[i] == s) {
			return;
		}
		if (blacklist[i] == "") break;
	}
	for (int i = 0; i < 1009; i++) {
		if (guest[i] && guest[i]->get_name() == s) {
			income = (m < 0 && (-1) * m >= guest[i]->get_money()) ? income + guest[i]->get_money() : income - m;
			guest[i]->Win(m);
			if (2 * guest[i]->get_skill() < m || guest[i]->get_money() <= 0) {
				for (int j = 0; j < 1009; j++) {
					if (blacklist[j] == "") {blacklist[j] = s; break;}
				}
				delete guest[i];
				guest[i] = NULL;
				guest_num--;
			}
			break;
		}
		if (guest[i]) cnt++;
		if (cnt >= guest_num) break;
	}
}

void Casino::EndDay() {
	//cout << "Today Casino earn: " << income << '\n';
	for (int i = 0; i < 1009; i++) {
		if (guest_num == 0) break;
		if (guest[i]) {
			delete guest[i];
			guest[i] = NULL;
			guest_num--;
		}
	}
	//cout << "End of a day!\n";
}

void Casino::Result() {
	cout << income << '\n';
	for (int i = 0; i < 1009; i++) {
		if (blacklist[i] == "") break;
		cout << blacklist[i] << '\n';
	}
}