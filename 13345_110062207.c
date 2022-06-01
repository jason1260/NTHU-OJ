#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char par[16] = {0};
char init[16] = {0};
long long int ans[10010] = {0};
int sort(void *a, void *b);
long long int factorial(int n);
int main () {
    int num;
    int i, j, k, a;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        for (j = 0; j < 16; j++) par[j] = 0;
        scanf("%s", par);
        int len = strlen(par);
        for (j = 0; j < 16; j++) init[j] = par[j];
        qsort(init, len, sizeof(char), sort);
        for (j = 0; j < strlen(par); j++) {
            for (k = 0; k < strlen(init); k++) {
                if (init[k] == par[j]) {
                    ans[i] += factorial(--len) * k;
                    for (a = k; a < strlen(init); a++) init[a] = init[a + 1];
                    break;
                }
            }
        }
    }
    for (i = 0; i < num; i++) printf("%lld\n", ans[i]);
        
    return 0;
}

int sort(void *a, void *b) {
    return (*(char *)a - *(char *)b);
}