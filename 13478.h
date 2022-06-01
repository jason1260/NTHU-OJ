#include <iostream>
#include <cstdlib>
#include "function.h"
using namespace std;

void LinkedList::reverse(int left, int right) {
    if (!head || left == right) return;
    Node *emp = new Node(0);
    emp->next = head;
    head = emp;
    for (int i = 0; i < left - 1; i++) {
        emp = emp->next;
    }
    Node *back = emp;
    for (int i = left; i <= right; i++) {
        back = back->next;
    }
    Node *n = emp->next;
    Node *n_next = n->next;
    Node *n_next_next;
    emp->next = back;
    n->next = back->next;
    while (n_next->next != back->next) {
        n_next_next = n_next->next;
        n_next->next = n;
        n = n_next;
        n_next = n_next_next;
    }
    n_next->next = n;
    head = head->next;
}