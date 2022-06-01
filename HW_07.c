#include <stdio.h>
char map[110][110];
char word[11] = "ICPCASIASG";
void dfs(int i, int x, int y);
int flag = 0;
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%c", &map[i + 2][j + 2]);
    for (int i = 2; i < n + 2; i++) {
        for (int j = 2; j < n + 2; j++) {
            if (map[i][j] == 'I') {
                char tmp = map[i][j];
                map[i][j] = 0;
                dfs(1, i, j);
                map[i][j] = tmp;
            }
        }
    }
    (!flag) ? printf("NO\n") : printf("YES\n");
}

void dfs(int i, int x, int y) {
    if (i == 9) { flag++; return;}
    if (!flag && map[x - 2][y - 1] == word[i]) dfs(i + 1, x - 2, y - 1);
    if (!flag && map[x - 2][y + 1] == word[i]) dfs(i + 1, x - 2, y + 1);
    if (!flag && map[x + 2][y - 1] == word[i]) dfs(i + 1, x + 2, y - 1);
    if (!flag && map[x + 2][y + 1] == word[i]) dfs(i + 1, x + 2, y + 1);
    if (!flag && map[x - 1][y - 2] == word[i]) dfs(i + 1, x - 1, y - 2);
    if (!flag && map[x - 1][y + 2] == word[i]) dfs(i + 1, x - 1, y + 2);
    if (!flag && map[x + 1][y - 2] == word[i]) dfs(i + 1, x + 1, y - 2);
    if (!flag && map[x + 1][y + 2] == word[i]) dfs(i + 1, x + 1, y + 2);
}