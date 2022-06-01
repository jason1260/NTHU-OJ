#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
typedef unsigned int u32;
using namespace std;
vector<string> taskList;
template <class T> class Manager;
class Node{
    private:
        string id;
        u32 time;
    public:
        Node(string id, u32 time);
        bool isAssigned;
        u32 get_time();
        string get_id();
        void set_time(u32 time);
        friend ostream& operator<<(ostream& os, Node& d);
};
Node::Node(string id, u32 time){
    this->id = id;
    this->time = time;
    isAssigned = false;
}
u32 Node::get_time(){
    return time;
};
void Node::set_time(u32 time){
    this->time = time;
};
string Node::get_id(){
    return id;
};

bool operator== (Node& node1, Node& node2){
    return node1.get_time() == node2.get_time();
}

bool operator== (Node& node1, u32 time){
    return node1.get_time() == time;
}

bool operator!= (Node& node1, Node& node2){
    return node1.get_time() != node2.get_time();
}

bool operator!= (Node& node1, u32 time){
    return node1.get_time() != time;
}

bool operator< (Node& node1, Node& node2){
    if(node1.get_time() == node2.get_time()){
        return node1.get_id() < node2.get_id();
    }
    return node1.get_time() < node2.get_time();
}

bool operator< (Node& node1, u32 time){
    return node1.get_time() < time;
}

bool operator> (Node& node1, Node& node2){
    if(node1.get_time() == node2.get_time()){
        return node1.get_id() > node2.get_id();
    }
    return node1.get_time() > node2.get_time();
}

bool operator> (Node& node1, u32 time){
    return node1.get_time() > time;
}

bool operator<= (Node& node1, Node& node2){
    return node1.get_time() <= node2.get_time();
}

bool operator<= (Node& node1, u32 time){
    return node1.get_time() <= time;
}

bool operator>= (Node& node1, Node& node2){
    return node1.get_time() >= node2.get_time();
}

bool operator>= (Node& node1, u32 time){
    return node1.get_time() >= time;
}

void operator+= (Node& node1,u32 time){
    node1.set_time(node1.get_time() + time);
}

ostream& operator<<(ostream& os, Node& n) {
    os << n.id << " AT " << n.time;
    return os;
}

template < class T >
class BinaryHeap{
    private:
        vector<T> heap;
        u32 parent_idx(u32 idx);
        u32 left_idx(u32 idx);
        u32 right_idx(u32 idx);
        // heapify from idx to root.
        void heapify_up(int idx);
        // heapify from idx to leaf.
        void heapify_down(int idx);
    public:
        friend class Manager<T>;  
        // get number of element in heap. 
        u32 size();
        // insert element to heap.
        void insert(T element);
        // remove minimum element from heap.
        void del_min();
        // get minimum element from heap.
        T get_min();
};
template <class T>
u32 BinaryHeap<T>::parent_idx(u32 idx){
    if (idx <= 1) return 0;
    return idx / 2;
}
template <class T>
u32 BinaryHeap<T>::left_idx(u32 idx){
    if (idx * 2 >= heap.size()) return heap.size();
    return idx * 2;
}
template <class T>
u32 BinaryHeap<T>::right_idx(u32 idx){
    if (idx * 2 + 1 >= heap.size()) return heap.size();
    return idx * 2 + 1;
}
template <class T>
void BinaryHeap<T>::heapify_up(int idx){
    while (parent_idx(idx) >= 1 && heap[idx] < heap[parent_idx(idx)]) {
        Node tmp = heap[idx];
        heap[idx] = heap[parent_idx(idx)];
        heap[parent_idx(idx)] = tmp;
        idx = parent_idx(idx);
    }   
}
template <class T>
void BinaryHeap<T>::heapify_down(int idx){
    while (left_idx(idx) < heap.size()) {
        if (right_idx(idx) < heap.size() && heap[right_idx(idx)] < heap[left_idx(idx)]) {
            if (heap[idx] > heap[right_idx(idx)]) {
                swap(heap[idx], heap[right_idx(idx)]);
                idx = right_idx(idx);
            }
            else break;
        }
        else {
            if (heap[idx] > heap[left_idx(idx)]) {
                swap(heap[idx], heap[left_idx(idx)]);
                idx = left_idx(idx);
            }
            else break;
        }
    }
}
template <class T>
u32 BinaryHeap<T>::size(){
    return heap.size();
}
template <class T>
void BinaryHeap<T>::insert(T element){
    heap.emplace_back(element);
    heapify_up(heap.size() - 1);
}
template <class T>
T BinaryHeap<T>::get_min(){
    if (heap.size() <= 1) return heap[0];
    return heap[1];
}
template <class T>
void BinaryHeap<T>::del_min(){
    if (heap.size() == 1) return;
    swap(heap[1], heap[heap.size() - 1]);
    heap.pop_back();
    heapify_down(1);
}

template < class T >
class Manager{
    private:
        BinaryHeap<T> taQue;
        int endTime;
        //int finish_in_time(u32 costTime,u32 deadLine);
    public:
        Manager();
        void cmd_set_endTime(u32 endTime);  // time complexity: O(n)
        void cmd_add_task(string taskName, u32 costTime);    // time complexity: O(log n)
        void cmd_add_ta(std::string id, u32 begin); // time complexity: O(log n)
        void cmd_check_schedule(u32 costTime,u32 deadLine);   // time complexity: O(log n)
        void result();
};
template <class T>
Manager<T>::Manager(){
    Node n = Node("", 0);
    taQue.heap.push_back(n);
    endTime = -1;
}
template <class T>
void Manager<T>::cmd_set_endTime(u32 endTime){
    cout << "SET_ENDTIME ";
    if (endTime >= this->endTime || this->endTime == -1) {
        this->endTime = endTime;
        cout << "SUCCESS\n";
        return;
    }
    for (int i = 1; i < taQue.size(); i++) {
        if (taQue.heap[i].get_time() > endTime) {
            cout << "FAIL\n";
            return;
        }
    }
    this->endTime = endTime;
    cout << "SUCCESS\n";
}
template <class T>
void Manager<T>::cmd_add_task(string taskName,u32 costTime){
    Node m = taQue.get_min();
    cout << "ADD_TASK " << taskName << ": ";
    if (taQue.size() == 1 || (m.get_time() + costTime > endTime && endTime != -1)) {
        cout << "FAIL\n";
        return;
    }
    m.set_time(costTime + m.get_time());
    taQue.heap[1] = m;
    taQue.heapify_down(1);
    cout << m << '\n';
}
template <class T>
void Manager<T>::cmd_add_ta(string id, u32 begin){
    cout << "ADD_TA ";
    if (begin > endTime && endTime != -1) cout << "FAIL\n";
    else {
        Node n = Node(id, begin);
        taQue.insert(n);
        cout << "SUCCESS\n";
    }
}
template <class T>
void Manager<T>::cmd_check_schedule(u32 costTime,u32 deadLine){
    cout << "CHECK_SCHEDULE: ";
    Node m = taQue.get_min();
    if (taQue.size() == 1) cout << "NO TA WARNING!\n";
    else if (m.get_time() + costTime <= deadLine && (m.get_time() + costTime <= endTime || endTime == -1)) cout << "CAN FINISH!\n";
    else cout << "OVERTIME WARNING!\n";
}
template <class T>
void Manager<T>::result(){
    cout << "NUMBER_TA: " << taQue.size() - 1 << '\n';
    if (taQue.size() == 1) return;
    //for (int i = 1; i < taQue.size(); i++) cout << taQue.heap[i].get_id() << ' ' << taQue.heap[i].get_time() << '\n';
    Node m = taQue.get_min();
    cout << "EARLIEST FINISH TA: " << m << '\n';
}
template Manager<Node>::Manager();
template void Manager<Node>::cmd_set_endTime(u32 endTime);
template void Manager<Node>::cmd_check_schedule(u32 costTime,u32 deadLine);
template void Manager<Node>::cmd_add_task(string taskName,u32 costTime);
template void Manager<Node>::cmd_add_ta(std::string id, u32 begin);
template void Manager<Node>::result();

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