#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;
void constructTree(Node** head);
void printInfix(Node *root) {
    int flag = 0;
    if (!root) return;
    if ((root->data == '&' || root->data == '|') && (root->right->data == '&' || root->right->data == '|')) flag = 1;
    else flag = 0; 
    printInfix(root->left);
    printf("%c", root->data);
    if (flag) printf("(");
    printInfix(root->right);
    if (flag) printf(")");
}

void freeTree(Node *root);

#endif