#include <stdio.h>
int range[100001];
int ans[100001];

int main () {
    int n, c, q;
    int i, j;
    scanf("%d %d %d", &n, &c, &q);
    for (i = 0; i < n; i++) range[i] = i + 1;
    for (i = 0; i < c; i++) {
        int a, b, temp;
        scanf("%d %d", &a, &b);
        temp = range[a - 1];
        range[a - 1] = range[b - 1];
        range[b - 1] = temp;
    }
    for (i = 0; i < n; i++) ans[range[i] - 1] = i + 1;
    //for (i = 0; i < n; i++) printf("%d ", ans[i]);
    for (i = 0; i < q - 1; i++) {
        int a;
        scanf("%d", &a);
        printf("%d ", ans[a - 1]);
    }
    int a;
    scanf("%d", &a);
    printf("%d\n", ans[a - 1]);

    return 0;
}