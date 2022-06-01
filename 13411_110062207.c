#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int val;
    struct _Node *next;
} Node;
Node* insert_sorted_list(Node* head, int val);
Node* merge_sorted_list(Node** heads);
Node* create(int val);

Node* insert_sorted_list(Node* head, int val) {
    if (!head) {
        head = create(-1);
    }
    Node *index = head;
    Node *node = create(val);
    //printf("%d\n", node->val);
    if (!head->next) {
        head->next = node;
        return head;
    }
    while (index->next != NULL) {
        //printf("index = %d\n", index->next->val);
        if (node->val <= index->next->val) {
            node->next = index->next;
            index->next = node;
            return head;
        }
        else index = index->next;
    }
    index->next = node;
    return head;
}

Node* merge_sorted_list(Node** heads) { 
    Node *ans = create(-1);
    Node *del;
    if (heads[1]) {
        del = heads[1];
        heads[1] = heads[1]->next;
        free(del);
    } 
    if (heads[0]) {
        del = heads[0];
        heads[0] = heads[0]->next;
        free(del);
    }
    Node *tmp = ans, *tmp0 = heads[0], *tmp1 = heads[1];
    while (tmp0 && tmp1) {
        if (tmp0->val <= tmp1->val) {
            tmp->next = tmp0;
            tmp = tmp->next;
            tmp0 = tmp0->next;
        }
        else {
            tmp->next = tmp1;
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }
    }
    while(tmp0) {
        tmp->next = tmp0;
        tmp = tmp->next;
        tmp0 = tmp0->next;
    }
    while(tmp1) {
        tmp->next = tmp1;
        tmp = tmp->next;
        tmp1 = tmp1->next;
    }
    return ans->next;
}

Node* create(int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}