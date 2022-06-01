#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string>
#include <iostream>
using namespace std;
// [TODO]: Implement all member functions in BaseStack
template < class T >
struct Node {
    Node *next;
    T value;
    Node() : value(0), next(0){};
    Node(T in) : value(in), next(0){};
};
template < class T >
class BaseStack 
{
public:
    BaseStack() : _capacity(0){};
    ~BaseStack() {
        delete [] _stack;
    }
    bool empty() {return (!_capacity) ? true : false;}
    int size() { return _capacity; }
    T& top() {
        return (_capacity) ? *(_stack + _capacity - 1) : *_stack; 
    }
    void push(const T& item) {
        if (_capacity == cap) DoubleCapacity();
        if (empty()) {
            *_stack = item;
            _capacity++;
            return;
        }
        *(_stack + _capacity) = item;
        _capacity++;
    }
    void pop() {
        if (empty()) return;
        *(_stack + _capacity - 1) = 0;
        _capacity--;
    }
    T index(int W) {
        return *(_stack + W);
    }
    void DoubleCapacity() {
        cap *= 2;                            
        T *newStack = new T[cap];       
        for (int i = 0 ; i < cap / 2; i++) {
            newStack[i] = _stack[i];
        }
        delete [] _stack;
        _stack = newStack;
    }

private:
    T* _stack = new T[5];
    int _capacity;
    int cap = 5;
};

template < class T >
class BaseQueue
{
public:
    BaseQueue() : head(0), back(0), _capacity(0){};
    ~BaseQueue() {
        while (head) {
            Node<T> *del = head;
            head = head->next;
            delete del;
        }
    }

    // Check if the queue is empty
    bool empty() { return (!_capacity) ? true : false; }
    int size() { return _capacity; }
    T& front() { return head->value; }
    T& rear() { return back->value; }
    // Insert a new element at rear
    void push(const T& item) {
        if (empty()) {
            head = new Node<T> (item);
            back = head;
            _capacity++;
            return;
        }
        Node<T> *now = new Node<T> (item);
        back->next = now;
        back = now;
        _capacity++;
    }
    void pop() {
        if (empty()) return;
        Node<T> *del = head;
        head = head->next;
        delete del;
        _capacity--;
    }

private:
    Node<T> *head;
    Node<T> *back;
    int _capacity;
};
BaseStack<int> *Map;
BaseQueue<int> SpBullet;
int len;

int find_max(int W) {
    int max = 0;
    for (int i = 0; i < W; i++) {
        while (!Map[i].empty() && Map[i].top() == -1) Map[i].pop();
        if (Map[i].size() > max) max = Map[i].size();
    }
    return max;
}

void InitialzeStage(int W, int H) {
    Map = new BaseStack<int> [W];
    len = W;
    char tmp;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            getchar();
            cin >> tmp;
            (tmp == '_') ? Map[j].push(-1) : Map[j].push(tmp - '0');
        }
    }
}

void ShootNormal(int col, int W) {
    if (col < 0 || col >= W || Map[col].empty()) return;
    while (!Map[col].empty() && Map[col].top() == -1) Map[col].pop();
    if (Map[col].top() == 2) SpBullet.push(2);
    else if (Map[col].top() == 3) SpBullet.push(3);
    else if (Map[col].top() == 4) SpBullet.push(4);
    else if (Map[col].top() == 5) {
        Map[col].pop();
        int max_level = find_max(W);
        int st = ((col - 2) > 0) ? col - 2 : 0;
        int ed = ((col + 2) < W) ? col + 2 : W - 1;
        for (int i = st; i <= ed; i++) {
            if (max_level != Map[i].size()) {
                for (int j = 0; j < max_level - Map[i].size(); j++) Map[i].push(-1);
            }
            for (int j = 0; j < 3; j++) Map[i].push(1);
        }
        return;
    }
    if (!Map[col].empty()) Map[col].pop();
}

void ShootSpecial(int col, int W) {
    if (col < 0 || col >= W || SpBullet.empty()) return;
    int type = SpBullet.front();
    if (type == 2) {
        int st = ((col - 2) >= 0) ? col - 2 : 0;
        int ed = ((col + 2) < W) ? col + 2 : W;
        for (int i = st; i <= ed; i++) {
            ShootNormal(i, W);
        }
    }
    else if (type == 3) {
        for (int i = 0; i < 3; i++) ShootNormal(col, W);
    }
    else if (type == 4) {
        while (!Map[col].empty() && Map[col].top() == -1) Map[col].pop();
        /*if (Map[col].empty()) {
            SpBullet.pop();
            return;
        }*/
        int target = Map[col].top();
        while (Map[col].top() == -1 || Map[col].top() == target) {
            ShootNormal(col, W);
            if (Map[col].empty()) break;
        }
    }
    SpBullet.pop();
}
void FrontRow(int W) {
    int max_level = find_max(W);
    cout << "FRONT_ROW, LEVEL:" << max_level << '\n';
    if (!max_level) return;
    for (int i = 0; i < W; i++) {
        if (Map[i].size() < max_level || Map[i].empty() || Map[i].top() == -1) {
            (i != W - 1) ? cout << "_ " : cout << "_";
        }
        else (i != W - 1) ? cout << Map[i].top() << ' ' : cout << Map[i].top();
    }
    cout << '\n';
}
void ShowResult(int W) {
    cout << "END_RESULT:\n";
    int h = find_max(W);
    if (!h) return;
    for (int i = 0; i < h; i++) {
        for (int j= 0; j < W; j++) {
            if (i >= Map[j].size() || Map[j].index(i) == -1) {
                (j == W - 1) ? cout << "_" : cout << "_ ";
            } else {
                (j == W - 1) ? cout << Map[j].index(i) : cout << Map[j].index(i) << ' ';
            }
        }
        cout << '\n';
    }
}

// free the memory that allocated in the program.
void deleteStage() {
    for (int i = 0; i < len; i++) {
        Map[i].~BaseStack();
    }
    SpBullet.~BaseQueue();
}



// The codes bellow prevent you from importing C++ containers.
// Nothing needed to be implemented below.
// Do not modify the codes below.

#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif
