#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

template <class T> class LinkedList;
template <class T> class Node;

template <class T>
class Node {
    public:
        friend class LinkedList<T>;
        Node(T tx,T ty,T tfence) {
            x = tx;
            y = ty;
            fence = tfence;
            next = NULL;
        };
        int compare(T tx,T ty) { //return 1 if this node is greater than target.
            if (x == tx && y == ty) return -1;
            if (y > ty || (y == ty && x > tx)) return 1;
            return 0;
        }
    private:
        T x;
        T y;
        T fence;
        Node<T>* next;
};
template <class T>
class LinkedList {
    public:
        LinkedList() {
            first = new Node<T> (1e10 * (-1), 1e10 * (-1), 0);
            length = 0;
        };
        void insert(T x, T y,int fence) {
            if (!length) {
                Node<T> *n = new Node<T> (x, y, fence);
                first->next = n;
                length++;
            }
            else {
                Node<T> *index = first;
                while (index->next) {
                    //cout << "next: " << index->next->x << " " << index->next->y << '\n';
                    int flag = index->next->compare(x, y);
                    if (flag == -1) {
                        if (!index->next->fence && fence) index->next->fence = fence;
                        return;
                    }
                    else if (flag == 0) index = index->next;
                    else if (flag == 1) break;
                }
                Node<T> *n = new Node<T> (x, y, fence);
                n->next = index->next;
                index->next = n;
                length++;
            }
        }
        void deletion(Node<T> **index, T x, T y) {
            //cout << x << ' ' << y << '\n';
            //cout << (*index)->next->compare(x, y) << '\n';
            if (!length) return;
            while ((*index)->next && (*index)->next->compare(x, y) != 1) {
                //cout << (*index)->next->x << ' ' << (*index)->next->y << '\n';
                if ((*index)->next->compare(x, y) == -1 && !(*index)->next->fence) {
                    Node<T> *del = (*index)->next;
                    (*index)->next = del->next;
                    delete del;
                    length--;
                    break;
                }
                else (*index) = (*index)->next;
            }
        }
        void deletion_ord(T x, T y) {
            if (!length) return;
            Node<T> *index = first;
            deletion(&index, x, y - 1);
            deletion(&index, x - 1, y);
            deletion(&index, x, y);
            deletion(&index, x + 1, y);
            deletion(&index, x, y + 1);
        }
        void deletion_sup(T x, T y) {
            if (!length) return;
            Node<T> *index = first;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    deletion(&index, x + j, y + i);
                }
            }
        }
        void show() {
            cout << "Display\n";
            if (!length) return;
            for (Node<T> *index = first->next; index; index = index->next) 
                cout << '(' << index->x << ',' << index->y << ')' << "\n";
        }
    private:
        Node<T>* first;
        int length;
};
LinkedList<ll> map;
void plant(ll x,ll y,int withFence) {
    map.insert(x, y, withFence);
}
void thief(ll x,ll y) {
    map.deletion_ord(x, y);
}
void superThief(ll x,ll y) {
    map.deletion_sup(x, y);
}
void display() {
    map.show();
}