#include <stdio.h>
#include <stdlib.h>
typedef struct _tree {
    struct _tree *l;
    struct _tree *r;
    int value;
} Tree;
Tree *root;
int max = 0;
int levelSum[100010];
int levelCount[100010];
char isOccupy[100010];
void makeTree(int n);
void Print(Tree *root);
void Sum();
void Aver();
void GMax(Tree *root, int n);
int main() {
    int n;
    scanf("%d", &n);
    makeTree(n);
    GMax(root, 1);
    scanf("%d", &n);
    while (n--) {
        char command[15];
        scanf("%s", command);
        if (command[0] == 'P') { 
            if (!root) printf("NULL\n");
            else {
                Print(root); 
                printf("\n");
            }
        }
        else if (command[0] == 'S') Sum();
        else if (command[0] == 'A') Aver();
        else if (command[0] == 'G') printf("%d\n", max);
    }
}
void makeTree(int n) {
    while (n--) {
        int k;
        scanf("%d", &k);
        if (isOccupy[k]) continue;
        else isOccupy[k] = 1;
        if (!root) {
            root = (Tree *) malloc(sizeof(Tree));
            root->l = NULL;
            root->r = NULL;
            root->value = k;
            continue;
        }
        Tree *now = (Tree *) malloc(sizeof(Tree));
        now->l = NULL;
        now->r = NULL;
        now->value = k;
        Tree *index = root;
        while (index) {
            if (k > index->value) {
                if (index->r) index = index->r;
                else { index->r = now; break;}
            }
            else {
                if (index->l) index = index->l;
                else { index->l = now; break;}
            }
        }
    }
}
void Print(Tree *root) {
    if (!root) return;
    Print(root->l);
    printf("%d ", root->value);
    Print(root->r);
}
void Sum() {
    int tmp;
    scanf("%d", &tmp);
    (tmp > max || !tmp) ? printf("0\n") : printf("%d\n", levelSum[tmp]);
}
void Aver() {
    int tmp;
    scanf("%d", &tmp);
    (tmp > max || !tmp) ? printf("0\n") : printf("%.3f\n", 1.0f * levelSum[tmp] / levelCount[tmp]);
}
void GMax(Tree *root, int n) {
    if (!root) return;
    levelSum[n] += root->value;
    levelCount[n]++;
    if (n > max) max = n;
    GMax(root->l, n + 1);
    GMax(root->r, n + 1);
}