#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED 
#include <stdlib.h>

typedef struct _Tree_Node{
    int number;
    struct _Tree_Node* parent;
    struct _Tree_Node* left;
    struct _Tree_Node* right;
}Tree_Node;

Tree_Node* tree_head;

void add_node(int n) {
    if (!tree_head) {
        tree_head = (Tree_Node *) malloc(sizeof(Tree_Node));
        tree_head->number = n;
        tree_head->left = NULL;
        tree_head->right = NULL;
        tree_head->parent = NULL;
        return;
    }
    Tree_Node *index = tree_head;
    while (index) {
        if (index->number < n) {
            if (index->right) index = index->right;
            else break;
        }
        else {
            if (index->left) index = index->left;
            else break;
        }
    }
    //printf("num = %d\n", index->number);
    Tree_Node *tmp = (Tree_Node *) malloc(sizeof(Tree_Node));
    tmp->number = n;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = index;
    if (index->number < n) index->right = tmp;
    else index->left = tmp;
    //printf("done\n");
    return;
}
void showtree(Tree_Node* treenow) {
    if (!treenow) return;
    showtree(treenow->left);
    printf("%d ", treenow->number);
    showtree(treenow->right);
}

#endif



