#include <stdio.h>
int board[9][9];
int footStep[85][2];
int check(int i, int j, int index);
int main () {
    int i = 0, j = 0;
    int index = 1;
    int count = -1;
    for (i = 0; i < 9; i++) for (j = 0; j < 9; j++) scanf("%d", &board[i][j]);
    i = 0;
    j = 0;
    int k;
    while(i < 9) {
        while(j < 9) {
            if (board[i][j] != 0) {
                j++;
                continue;
            }
            else {
                if (check(i, j, index)) {
                    board[i][j] = index;
                    index = 1;
                    count++;
                    footStep[count][0] = i;
                    footStep[count][1] = j;
                    j++;
                }
                else {
                    if (index < 9) index++;
                    else {
                        board[i][j] = 0;
                        i = footStep[count][0];
                        j = footStep[count][1];
                        while (board[i][j] == 9) {
                            board[i][j] = 0;
                            i = footStep[--count][0];
                            j = footStep[count][1];
                        }
                        count--;
                        if (board[i][j] != 9) index = board[i][j] + 1;
                        board[i][j] = 0;
                    }
                }
            }
        }
        i++;
        j = 0;
        index = 1;
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                printf("no solution\n");
                return 0;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) j != 8 ? printf("%d ", board[i][j]) : printf("%d", board[i][j]);
        printf("\n");
    }

    return 0;
}

int check(int i, int j, int index) {
    int a, b;
    for (a = 0; a < 9; a++) {
        if (a != i && board[a][j] == index) return 0;
    }
    for (a = 0; a < 9; a++) if (a != j && board[i][a] == index) return 0;
    if (i < 3) {
        if (j < 3) {
            for (a = 0; a < 3; a++) for (b = 0; b < 3; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
        else if (j < 6) {
            for (a = 0; a < 3; a++) for (b = 3; b < 6; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
        else {
            for (a = 0; a < 3; a++) for (b = 6; b < 9; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
    }
    else if (i < 6) {
        if (j < 3) {
            for (a = 3; a < 6; a++) for (b = 0; b < 3; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
        else if (j < 6) {
            for (a = 3; a < 6; a++) for (b = 3; b < 6; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
        else {
            for (a = 3; a < 6; a++) for (b = 6; b < 9; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
    }
    else {
        if (j < 3) {
            for (a = 6; a < 9; a++) for (b = 0; b < 3; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
        else if (j < 6) {
            for (a = 6; a < 9; a++) for (b = 3; b < 6; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
        else {
            for (a = 6; a < 9; a++) for (b = 6; b < 9; b++) if ((a != i || b != j) && board[a][b] == index) return 0;
        }
    }

    return 1;
}