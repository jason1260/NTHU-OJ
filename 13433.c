#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    struct _node *l;
    struct _node *r;
    int value;
} Node;
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        Node *head = (Node *) malloc(sizeof(Node));
        Node *index = head;
        head->l = NULL;
        head->r = NULL;
        head->value = 0;
        int k;
        scanf("%d", &k);
        getchar();
        for (int i = 1; i <= k; i++) {
            char tmp;
            scanf("%c", &tmp);
            if (tmp == 'R') {
                if (!index->r) {
                    index->r = (Node *) malloc(sizeof(Node));
                    index->r->l = index;
                    index->r->r = NULL;
                    index->r->value = i;
                    index = index->r;
                }
                else {
                    Node *nw = (Node *) malloc(sizeof(Node));
                    nw->value = i;
                    nw->l = index;
                    nw->r = index->r;
                    index->r->l = nw;
                    index->r = nw;
                    index = index->r;
                }
            }
            else {
                if (!index->l) {
                    index->l = (Node *) malloc(sizeof(Node));
                    index->l->r = index;
                    index->l->l = NULL;
                    index->l->value = i;
                    index = index->l;
                    head = index;
                }
                else {
                    Node *nw = (Node *) malloc(sizeof(Node));
                    nw->value = i;
                    nw->r = index;
                    nw->l = index->l;
                    index->l->r = nw;
                    index->l = nw;
                    index= index->l;
                }
            }
        }
        for (; head; head = head->r) {
            printf("%d ", head->value);
        }
        printf("\n");
        getchar();
    }
}