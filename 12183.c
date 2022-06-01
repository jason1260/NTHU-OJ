#include <stdio.h>
#include <stdlib.h>
typedef enum {NUM, AND, OR} TokenType;
typedef struct node{
    int value;
    TokenType type;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent; 
} Node;
Node* root;
Node* list[100001];
void input_parsing();
void update(int id);
int m, k;
void freeTree(Node *root){
    if (root != NULL) {
        freeTree(root->leftchild);
        freeTree(root->rightchild);
        free(root);
    }
}
int main () {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d\n", &m, &k);
        input_parsing();
        while (k--) {
            int id;
            scanf("%d", &id);
            list[id]->value = !list[id]->value;
            update(id);
            printf("%d\n", root->value);
        }
        //freeTree(root);
    }
}
void input_parsing() {
    char tmp;
    Node* index;
    scanf("%c", &tmp);
    if (tmp == '&' || tmp == '|') {
        root = (Node *) malloc(sizeof(Node));
        root->type = (tmp == '&') ? AND : OR;
        root->value = 0;
        root->parent = NULL;
        root->leftchild = NULL;
        root->rightchild = NULL;
        index = root;
    }
    else if (tmp == '[') {
        int id;
        scanf("%d]", &id);
        list[id] = (Node *) malloc(sizeof(Node));
        root = list[id];
        root->parent = NULL;
        root->leftchild = NULL;
        root->rightchild = NULL;
        root->type = NUM;
        root->value = 0;
        return;
    }
    scanf("%c", &tmp);
    while (m) {
        if (tmp == '&' || tmp == '|') {
            Node *n = (Node *) malloc(sizeof(Node));
            n->type = (tmp == '&') ? AND : OR;
            n->value = 0;
            n->leftchild = NULL;
            n->rightchild = NULL;
            while (index->leftchild && index->rightchild) index = index->parent;
            n->parent = index;
            if (!index->leftchild) index->leftchild = n;
            else index->rightchild = n;
            index = n;
        }
        else if (tmp == '[') {
            int id;
            scanf("%d]", &id);
            list[id] = (Node *) malloc(sizeof(Node));
            list[id]->leftchild = NULL;
            list[id]->rightchild = NULL;
            list[id]->type = NUM;
            list[id]->value = 0;
            while (index->leftchild && index->rightchild) index = index->parent;
            list[id]->parent = index;
            if (!index->leftchild) index->leftchild = list[id];
            else if (!index->rightchild) index->rightchild = list[id];
            m--;
        }
        scanf("%c", &tmp);
    }
}
void update(int id) {
    Node *index = list[id]->parent;
    while (index) {
        int try = index->value;
        if (index->type == AND) {
            index->value = index->leftchild->value & index->rightchild->value;
            //printf("AND value: %d %d\n", try, index->value);
            if (try == index->value) return;
        }
        else if (index->type == OR) {
            index->value = index->leftchild->value | index->rightchild->value;
            //printf("OR value: %d %d\n", try, index->value);
            if (try == index->value) return;
        }
        index = index->parent;
    }
}