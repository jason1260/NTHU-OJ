#include <stdio.h>
#include <math.h>
char carpet[6565][6565];
void dot(int len, int x, int y);
int main () {
    int len;
    int i, j;
    scanf("%d", &len);
    int midLen = pow(3, len - 1);
    for (i = 0; i < midLen * 3; i++) for (j = 0; j < midLen * 3; j++) carpet[i][j] = '.';
    int midPoint = pow(3, len) / 2;
    dot(midLen, midPoint, midPoint);
    for (i = 0; i < midLen * 3; i++) {
        for (j = 0; j < midLen * 3; j++) printf("%c", carpet[i][j]);
        printf("\n");
    }

    return 0;
}

void dot(int len, int x, int y) {
    int i, j;
    for (i = x - len / 2; i <= x + len / 2; i++) for (j = y - len / 2; j <= y + len / 2; j++)
            carpet[i][j] = '#';
    if (len / 3 == 0) return 0;
    dot(len / 3, x - len, y - len);
    dot(len / 3, x, y - len);
    dot(len / 3, x + len, y - len);
    dot(len / 3, x - len, y);
    dot(len / 3, x + len, y);
    dot(len / 3, x - len, y + len);
    dot(len / 3, x, y + len);
    dot(len / 3, x + len, y + len);
}