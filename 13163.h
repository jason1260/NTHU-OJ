#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	Node(int x) : prev(0), next(0), val(x), tag(0){};
    Node *prev;
    Node *next;
    int val;
    int tag;
};

class KuoYangPresent {
public:
	KuoYangPresent(int k);
	void Push(int x);
	void Pop();
	void ProgrammingTanoshi();
	void KuoYangTeTe();
	void PrintList(); 
	
private:
	Node *head, *mid, *tail;
	int sz, k;
};
Node *tete;
KuoYangPresent::KuoYangPresent(int tk) : head(0), mid(0), tail(0), sz(0), k(tk){};
void KuoYangPresent::Push(int x) {
	if (!sz) {
		head = new Node(x);
		mid = tail = tete = head;
		sz++;
	}
	else {
		Node *n = new Node(x);
		tail->next = n;
		n->prev = tail;
		tail = n;
		sz++;
		if (sz & 1) mid = mid->next;
	}
	//cout << tete->val << '\n'; 
}
void KuoYangPresent::Pop() {
	if (!sz) return;
	if (head == mid) {
		Node *del = head;
		if (tete == mid) tete = head->next;
		//cout << tete->val << 'k' << '\n';
		head = head->next;
		mid = head;
		if (!head) tail = NULL;
		head->prev = NULL;
		delete del;
		sz--;
	}
	else {
		Node *del = mid;
		if (tete == mid) tete = tete->prev;
		//cout << tete->val << 'h' << '\n';
		mid->prev->next = mid->next;
		mid->next->prev = mid->prev;
		mid = (sz & 1) ? mid->prev : mid->next;
		delete del;
		sz--; 
	}
	//cout << tete->val << '\n';
}
void KuoYangPresent::ProgrammingTanoshi() {
	for (; tete->next; tete = tete->next) {
		tete->val %= k;
	}
	tete->val %= k;
}
void KuoYangPresent::PrintList() {
	for (Node *index = head; index; index = index->next) {
		cout << index->val << ' ';
	}
	cout << '\n';
}
void KuoYangPresent::KuoYangTeTe() {};