#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdlib.h>
#define MAXEXPR 256
#define NUMSYM 7

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start
typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* FACTOR();
BTNode* makeNode(char c);

BTNode* EXPR() {
    char tmp = expr[pos--];
    BTNode *r = (tmp == ')') ? FACTOR() : makeNode(tmp);
    if (pos < 0 || expr[pos] == '(') {
        return r;
    }
    BTNode *root = makeNode(expr[pos--]);
    BTNode *l = (!pos || expr[pos - 1] == '(') ? makeNode(expr[pos--]) : EXPR();
    root->left = l;
    root->right = r;
    return root;
}
BTNode* FACTOR() {
    char tmp = expr[pos--];
    BTNode *r = (tmp == ')') ? FACTOR() : makeNode(tmp);
    if (pos < 0 || expr[pos] == '(') {
        pos--; 
        return r;
    }
    BTNode *root = makeNode(expr[pos--]);
    BTNode *l = (!pos || expr[pos - 1] == '(') ? makeNode(expr[pos--]) : EXPR();
    root->left = l;
    root->right = r;
    pos--;
    return root;
}
BTNode* makeNode(char c) {
    BTNode *tmp = (BTNode *) malloc(sizeof(BTNode));
    tmp->left = NULL;
    tmp->right = NULL;
    if (c >= 'A' && c <= 'D') tmp->data = c - 65;
    else if (c == '&') tmp->data = OP_AND;
    else if (c == '|') tmp->data = OP_OR;
    return tmp;
}
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

#endif