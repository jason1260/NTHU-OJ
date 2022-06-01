#include <stdio.h>
#include <string.h>
int div();
char ans[505], operaters[505];
int index_op = 0, index = 0;
int main () {
    int i;
    div();
    for (i = 0; i < index; i++) printf("%c ", ans[i]);
    printf("%c", ans[i]);

    return 0;
}

int div() {
    char temp;
    if ((temp = getchar()) == ' ') temp = getchar();
    if (temp < 48) {
        operaters[index_op++] = temp;
        if (div() && div()) ans[index++] = operaters[--index_op];
    }
    else {
        ans[index++] = temp;
        return 1;
    }
}