#include <stdio.h>
#include <string.h>
int ocut[60], dcut[60];
int ans[110] = {0};
char o[5010], d[5010];
int main () {
    int t, ocount, dcount;
    int i, j, k, l;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int find;
        ocount = -1, dcount = -1;
        for (j = 0; j < 5010; j++) {
            o[j] = 0;
            d[j] = 0;
        }
        scanf("%s", o);
        scanf("%s", d);
        o[strlen(o)] = '/';
        d[strlen(d)] = '/';
        for (j = 0; j <= strlen(o); j++) if (o[j] == '/') ocut[++ocount] = j;
        for (j = 0; j <= strlen(d); j++) if (d[j] == '/') dcut[++dcount] = j;
        for (j = 0; j < dcount; j++) {           
            for (l = 0; l < ocount; l++) {
                int flag = 0;
                find = 0;
                if ((dcut[j + 1] - dcut[j]) != (ocut[l + 1] - ocut[l])) continue;
                for (k = 0; k <= ocut[l + 1] - ocut[l]; k++) {
                    if (d[dcut[j] + k] == o[ocut[l] + k]) flag++;
                    else break;
                    if (flag == ocut[l + 1] - ocut[l] + 1) find++;
                }
                if (find) {
                    break;
                }
            }
            if (!find) {
                ans[i]++;
                break;
            }
        }
    }
    for (i = 0; i < t; i++) (ans[i] == 0) ? printf("valid\n") : printf("not valid\n");

    return 0;
}