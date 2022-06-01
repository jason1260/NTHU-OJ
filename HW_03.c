#include <stdio.h>
#include <math.h>
int board[11][11];
void dfs(int i, int m, int n);
int check(int i, int j);
int max, count;
int main(void) {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2) {
        for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) board[i][j] = 0;
        max = m + n, count = 0;
        dfs(0, m, n);
        printf("%d\n", count);
    }
}

void dfs(int i, int m, int n) {
    if (i == max) {
        count++;
        return;
    }
    for (int j = 0; j < max; j++) {
        if (board[i][j]) continue;
        for (int k = i + 1; k < max; k++) board[k][j]++;
        if (m && check(i, j)) {
            for (int k = i + 1, l = j - 1; k < max && l >= 0; k++, l--) board[k][l]++;
            for (int k = i + 1, l = j + 1; k < max && l < max; k++, l++) board[k][l]++;
            dfs(i + 1, m - 1, n);
            for (int k = i + 1, l = j - 1; k < max && l >= 0; k++, l--) board[k][l]--;
            for (int k = i + 1, l = j + 1; k < max && l < max; k++, l++) board[k][l]--;
        }
        if (n) {
            board[i][j] = -1;
            dfs(i + 1, m, n - 1);
            board[i][j] = 0;
        }
        for (int k = i + 1; k < max; k++) board[k][j]--;
    }
}

int check(int i, int j) {
    for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--) if (board[k][l] == -1) return 0;
    for (int k = i - 1, l = j + 1; k >= 0 && l < max; k--, l++) if (board[k][l] == -1) return 0;
    return 1;
}