#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    struct Node *next[1001];
} node;
int len[1001];
int ans[1001];
int count;
node root[1001];
void dfs(int r, int n);
int cmp(const int *a, const int *b);

int main () {
    int n, k, s;
    int i, j;
    scanf("%d %d %d", &n, &k, &s);
    for (i = 0; i < k; i++) {
        int tmpa, tmpb;
        scanf("%d %d", &tmpa, &tmpb);
        root[tmpa].next[len[tmpa]++] = tmpb;
    }
    /*for (i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (j = 0; j < len[i]; j++) printf("%d ", root[i].next[j]);
        printf("\n");
    }*/
    ans[count++] = s;
    for (i = len[s] - 1; i >= 0; i--, len[s]--) {
        int tmp = root[s].next[i];
        int flag = 0;
        for (j = 0; j < count; j++) {
            if (tmp == ans[j]) {
                flag++;
                break;
            }
        }
        if (!flag) {
            root[s].next[i] = NULL;
            dfs(s, tmp);
            root[s].next[i] = tmp;
        }
    }
    qsort(ans, count, 4, cmp);
    for (i = 0; i < count; i++) {
        (i == count - 1) ? printf("%d\n", ans[i]) : printf("%d ", ans[i]);
    }

    return 0;
}

void dfs (int r, int n) {
    //printf("from %d to %d\n", r, n);
    ans[count++] = n;
    int i, j;
    for (i = len[n] - 1; i >= 0; i--, len[n]--) {
        int flag = 0;
        int tmp = root[n].next[i];
        for (j = 0; j < count; j++) {
            if (tmp == ans[j]) {
                flag++;
                break;
            }
        }
        if (!flag) {
            root[n].next[i] = NULL;
            dfs(n, tmp);
            root[n].next[i] = tmp;
        }
    }
}

int cmp(const int *a, const int *b) {
    return *a - *b;
}