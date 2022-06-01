#include <stdio.h>
#include <string.h>
int table[10][10010];
int len[10] = {0};
void print(void);
void all(void);
void place(void);
void swap(void);
void clear(void);
int main () {
    int i, j;
    char temp[10];
    while (scanf("%s", temp) == 1) {
        if (!strcmp(temp, "exit")) break;
        else if (temp[0] == 'p' && temp[1] == 'r') print();
        else if (temp[0] == 'a') all();
        else if (temp[0] == 'p' && temp[1] == 'l') place();
        else if (temp[0] == 's') swap();
        else if (temp[0] == 'c') clear();
    }
}   

void print(void) {
    int i, j;
    for (i = 0; i < 10; i++) {
        if (len[i] == 0) {
            printf("%d: No card\n", i);
            continue;
        }
        printf("%d: ", i);
        for (j = 0; j < len[i]; j++) {           
            (j != len[i] - 1) ? printf("%d ", table[i][j]) : printf("%d\n", table[i][j]);
        }
    }
}

void all(void) {
    int num, t;
    int i, j;
    scanf("%d %d", &num, &t);
    for (i = 0; i < 10; i++) for (j = 0; j < t; j++) table[i][j] = num;
    for (i = 0; i < 10; i++) len[i] = t;
}

void place(void) {
    int t, num;
    int i, j;
    scanf("%d %d", &t, &num);
    len[t] = num;
    for (i = 0; i < num; i++) scanf("%d", &table[t][i]);
}

void swap(void) {
    int x, y;
    int i, j;
    int temp;
    scanf("%d %d", &x, &y);
    int max = len[x];
    if (len[x] < len[y]) max = len[y];
    for (i = 0; i < max; i++) {
        temp = table[x][i];
        table[x][i] = table[y][i];
        table[y][i] = temp;
    }
    temp = len[x];
    len[x] = len[y];
    len[y] = temp;
}

void clear(void) {
    int i;
    for (i = 0; i < 10; i++) len[i] = 0;
}