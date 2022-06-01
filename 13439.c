#include <stdio.h>
#include <stdlib.h>
#define ll long long
typedef struct _node {
    struct _node *l;
    struct _node *r;
    ll value;
    int oper;
} Node;
int check(char *t);
Node *root;
Node *makeTree(void);
int main() {
    char tmp[20];
    scanf("%s", tmp);
    root = (Node *) malloc(sizeof(Node));
    root->value = -1;
    root->oper = tmp[0];
    root->l = makeTree();
    root->r = makeTree();
    if (tmp[0] == '+') root->value = root->l->value + root->r->value;
    else if (tmp[0] == '-') root->value = root->l->value - root->r->value;
    else if (tmp[0] == '*') root->value = root->l->value * root->r->value;
    else if (tmp[0] == '/') root->value = root->l->value / root->r->value;
    else root->value = root->l->value % root->r->value;
    printf("%lld\n", root->value);
}
Node *makeTree() {
    char tmp[20];
    scanf("%s", tmp);
    Node *index = (Node *) malloc(sizeof(Node));
    if (check(tmp)) {
        index->l = makeTree();
        index->r = makeTree();
        if (tmp[0] == '+') index->value = index->l->value + index->r->value;
        else if (tmp[0] == '-') index->value = index->l->value - index->r->value;
        else if (tmp[0] == '*') index->value = index->l->value * index->r->value;
        else if (tmp[0] == '/') index->value = index->l->value / index->r->value;
        else index->value = index->l->value % index->r->value;
        //printf("%s node with value %ld done\n", tmp, index->value);
    }
    else {
        index->l = NULL;
        index->r = NULL;
        index->value = atol(tmp);
        //printf("%ld leaf node done!\n", index->value);
    }
    return index;
}
int check(char *t) {
    return (*t == '+' || (*t == '-' && *(t + 1) == '\0') || *t == '*' || *t == '/' || *t == '%') ? 1 : 0;
}