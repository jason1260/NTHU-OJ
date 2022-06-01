#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num);
void AddBack(Node** head, Node** back, int num);
void DeleteFront(Node** head, Node** back);
void Delete(Node** head, Node** back, int num);
void Swap(Node** head, Node** back);

void AddFront(Node** head, Node** back, int num) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->idx = num;
    if (*head == *back && (*head)->idx == -1) {
        (*head)->next = tmp;
        (*back) = tmp;
        tmp->next = NULL;
    }
    else {
        tmp->next = (*head)->next;
        (*head)->next = tmp;
    }
    //printf("head = %d, back = %d, tmp = %d\n", (*head)->next->idx, (*back)->idx, (*tmp).idx);
}

void AddBack(Node** head, Node** back, int num) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->idx = num;
    tmp->next = NULL;
    (*back)->next = tmp;
    *back = tmp;
    //printf("head = %d, back = %d, tmp = %d\n", (*head)->next->idx, (*back)->idx, (*tmp).idx);
}

void DeleteFront(Node** head, Node** back) {
    if ((*head)->next == NULL) return;
    Node *tmp = (*head)->next;
    if (!tmp->next) {
        (*head)->next = NULL;
        //printf("head = %d, back = %d, tmp = %d\n", (*head)->next->idx, (*back)->idx, (*tmp).idx);
        free(tmp);
        return;
    }
    (*head)->next = (*head)->next->next;
    //printf("head = %d, back = %d, tmp = %d\n", (*head)->next->idx, (*back)->idx, (*tmp).idx);
    free(tmp);
}

void Delete(Node** head, Node** back, int num) {
    if (!(*head)->next) return;
    Node *del, *tmp;
    tmp = *head;
    while (tmp->next) {
        del = tmp->next;
        if (del->idx == num) {
            if (!del->next) *back = tmp;
            tmp->next = del->next;
            free(del);
        }
        else {
            tmp = tmp->next;
        }
    }
}

void Swap(Node** head, Node** back) {
    if (!(*head)->next || !(*head)->next->next) return;
    Node *tmp = (*head)->next, *tmp_next = (*head)->next->next, *tmp_next_next;
    tmp->next = NULL;
    *back = tmp;
    while (tmp_next->next) {
        tmp_next_next = tmp_next->next;
        tmp_next->next = tmp;
        tmp = tmp_next;
        tmp_next = tmp_next_next;
    }
    tmp_next->next = tmp;
    (*head)->next = tmp_next;
}