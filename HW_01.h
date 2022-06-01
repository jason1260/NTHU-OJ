#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data) {
    Node *head = (Node *) malloc(sizeof(Node));
    Node *index = head;
    head->next = *nd;
    for (int i = 1; i < data; i++) {
        if (index->next) index = index->next;
        else return;
    }
    Node *del = index->next;
    index->next = index->next->next;
    free(del);
    (*nd) = head->next;
}

Node* createList() {
    int tmp;
    Node *head = (Node *) malloc(sizeof(Node));
    Node *index = head;
    head->next = NULL;
    scanf("%d", &tmp);
    while (tmp != -1) {
        Node *new = (Node *) malloc(sizeof(Node));
        new->data = tmp;
        new->next = NULL;
        index->next = new;
        index = index->next;
        scanf("%d", &tmp);
    }
    return head->next;
}