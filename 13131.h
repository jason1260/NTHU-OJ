#ifndef function_h
#define function_h

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class MAX_HEAP{
public:
    MAX_HEAP():Count(0){}
    virtual ~MAX_HEAP() {}
    virtual void PUSH(const int &) = 0;
    virtual int MAX() const = 0;
    virtual int POP() = 0;
    int count() const { return Count; }// An empty tree has height of 0. A tree with only root node has height of 1.

protected:
    int Count;
};

class Array_MAX_HEAP : public MAX_HEAP{
public:
    Array_MAX_HEAP();
    virtual ~Array_MAX_HEAP() {}
    virtual void PUSH(const int &) override; //root node is stored at index 1.
    virtual int MAX() const override;
    virtual int POP() override;

private:
    int array[1025];
};
Array_MAX_HEAP::Array_MAX_HEAP() {
    array[0] = -1;
    Count = 0;
}
void Array_MAX_HEAP::PUSH(const int &a) {
    array[++Count] = a;
    int idx = Count;
    while (array[idx] > array[idx / 2] && idx != 1) {
        swap(array[idx], array[idx / 2]);
        idx /= 2;
    }
}
int Array_MAX_HEAP::MAX() const {
    if (!Count) return -1;
    else return array[1];
}
int Array_MAX_HEAP::POP() {
    if (!Count) return -1;
    int m = array[1];
    swap(array[1], array[Count]);
    array[Count] = 0;
    Count--;
    int idx = 1;
    while (idx * 2 <= Count) {
        if (idx * 2 + 1 <= Count && array[idx * 2 + 1] > array[idx * 2]) {
            if (array[idx * 2 + 1] > array[idx]) {
                swap(array[idx * 2 + 1], array[idx]);
                idx = idx * 2 + 1;
            }
            else break;
        }
        else if (array[idx * 2] > array[idx]) {
            swap(array[idx * 2], array[idx]);
            idx = idx * 2;
        }
        else break;
    }
    return m;
}

class ListNode{
    friend class List_MAX_HEAP; //make List_BST a friend

public:
    ListNode(const int &info):value( info ),left( NULL ),right( NULL ), parent(NULL) //constructor
    {
    }//end ListNode constructor

private:
    int value;
    ListNode *left;
    ListNode *right;
    ListNode *parent;
};//end class ListNode

class List_MAX_HEAP : public MAX_HEAP{
public:
    List_MAX_HEAP();
    virtual ~List_MAX_HEAP()
    {
        deleteTree(root);
    }
    virtual void PUSH(const int &) override;
    virtual int MAX() const override;
    virtual int POP() override;

private:
    ListNode *root;
    /* clean a tree.*/
    void deleteTree(ListNode *root);
    ListNode* findparent(int cnt, ListNode* root){//find the parent of node cnt
        //cout << "enter\n"; 
        if(cnt <= 1) return root;
        string s = "";
        int n = 1;
        while(cnt !=0){
            s += cnt%2 +'0';
            cnt/=2;
        }ListNode *now = root;
        for(int i = s.size()-2; i > 0; i--){
            if(s[i] == '0'){
                now = now->left;
                n = n*2;
            }else{
                now = now->right;
                n = n*2+1;
            }
        }
        return now;
    }
};
List_MAX_HEAP::List_MAX_HEAP() {
    Count = 0;
    root = NULL;
}
void List_MAX_HEAP::deleteTree(ListNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
void List_MAX_HEAP::PUSH(const int &a) {
    ListNode *n = new ListNode(a);
    Count++;
    if (Count == 1) {
        root = n;
        return;
    }
    ListNode *pr = findparent(Count, root);
    if (Count & 1) {
        pr->right = n;
        n->parent = pr;
    }
    else {
        pr->left = n;
        n->parent = pr;
    }
    ListNode* idx = n;
    while (idx->parent && idx->value > idx->parent->value) {
        int tmp = idx->value;
        idx->value = idx->parent->value;
        idx->parent->value = tmp;
        idx = idx->parent;
    }
}
int List_MAX_HEAP::MAX() const {
    if (!Count) return -1;
    return root->value;
}
int List_MAX_HEAP::POP() {
    if (!Count) return -1;
    int m = root->value;
    if (Count == 1) {
        delete root;
        root = NULL;
        Count--;
        return m;
    }
    ListNode* tail = findparent(Count * 2, root);
    if (Count & 1) tail->parent->right = NULL;
    else tail->parent->left = NULL;
    root->value = tail->value;
    tail->value = m;
    delete tail;
    Count--;
    ListNode* idx = root; 
    while (idx->left) {
        if (idx->right && idx->right->value > idx->left->value) {
            if (idx->right->value > idx->value) {
                int tmp = idx->value;
                idx->value = idx->right->value;
                idx->right->value = tmp;
                idx = idx->right;
            }
            else break;
        }
        else if (idx->left->value > idx->value) {
            int tmp = idx->value;
            idx->value = idx->left->value;
            idx->left->value = tmp;
            idx = idx->left;
        }
        else break;
    }
    return m;
}

#endif /* function_h */
