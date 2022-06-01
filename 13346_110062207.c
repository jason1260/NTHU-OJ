#include <stdio.h>
int last(int x, int y, int l, int w, char m[20][20]);
int portal[2][3] = {{0, 0, 0}, {0, 0, 0}};
int ans[20][20];
int p = 0, count = 0, l, w;
char map[20][20];
int main() {
    int i, j; 
    scanf("%d %d", &l, &w); 
    for (i = 0; i < l; i++) {
        for (j = 0; j < w; j++) ans[i][j] = 0;
    }
    getchar();
    for (i = 0; i < l; i++) {
        for (j = 0; j < w; j++) map[i][j] = getchar();
        getchar();
    }
    for (i = 0; i < l; i++) ans[i][0] = 1;
    for (i = 0; i < w; i++) ans[0][i] = 1;
    for (i = 1; i < l; i++) {
        for (j = 1; j < w; j++) {
            if (map[i][j] == '0')
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1] + ans[i - 1][j - 1];
            else {
                ans[i][j] = 0;
                portal[p][0] = i;
                portal[p][1] = j;
                portal[p][2] = ans[i - 1][j] + ans[i][j - 1] + ans[i - 1][j - 1];
                p++;
            }
        }
    }
    if (p == 2) {
        dfs(0, 0);
        printf("%d\n", count);
        return 0;
    }
    for (i = 0; i < l; i++) ans[i][0] = 1;
    for (i = 0; i < w; i++) ans[0][i] = 1;
    for (i = 1; i < l; i++) {
        for (j = 1; j < w; j++) {
            if (map[i][j] == '0')
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1] + ans[i - 1][j - 1];
            else
                ans[i][j] = 0;
        }
    }
    if (p == 0) 
        printf("%d\n", ans[l - 1][w - 1]);
    else {
        int portal1 = portal[0][2] * last(portal[0][0] - 2, portal[0][1] - 2, l, w, map);
        printf("%d\n", ans[l - 1][w - 1] + portal1);
    }

    return 0;
}

int last(int x, int y, int l, int w, char m[20][20]) {
    int i, j;
    int c = 0, d = 0;
    int an[20][20];
    char mm[20][20];
    for (i = x; i < l; i++) for (j = y; j < w; j++) mm[i][j] = m[i][j];
    mm[x + 2][y + 2] = '0';
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) an[i][j] = 0;
    }
    int flag = 0;
    for (i = x; i < l; i++) {
        for (j = y; j < w; j++) {
            if (mm[i][j] == '0') {
                if (i == x || j == y) an[i][j] = 1;
                else an[i][j] = an[i - 1][j] + an[i][j - 1] + an[i - 1][j - 1];
            }
            else {
                an[i][j] = last(i - 2, j - 2, l, w, mm);
                c = an[i][j];
                flag++;
                break;
            }
        }
        if (flag) break;
    }

    int flag_i = 0, flag_j = 0;
    for (i = x; i < l; i++) {
        for (j = y; j < w; j++) {
            if (mm[i][j] == '0') {
                if (i == x || j == y) {
                    if ((i == x && flag_i) || (j == x && flag_j)) an[i][j] = 0;
                    else an[i][j] = 1;
                }
                else an[i][j] = an[i - 1][j] + an[i][j - 1] + an[i - 1][j - 1];
            }
            else {
                if (i == x) flag_i++;
                if (j == y) flag_j++;
                if (i == x || j == y) d = 1;
                else d = an[i - 1][j] + an[i][j - 1] + an[i - 1][j - 1];
                an[i][j] = 0;
            }
        }
    }
    return c * d + an[l - 1][w - 1];
}

void dfs(int x, int y) {
    if (x == l - 1 && y == w - 1) {
        count++;
        return 0;
    }
    if (map[x][y] == '1') {
        map[x][y] = '0';
        dfs(x - 2, y - 2);
        map[x][y] = '1';
    }
    else {
        if (x == l - 1) dfs(x, y + 1);
        else if (y == w - 1) dfs(x + 1, y);
        else {
            dfs(x, y + 1);
            dfs(x + 1, y);
            dfs(x + 1, y + 1);
        }
    }
}