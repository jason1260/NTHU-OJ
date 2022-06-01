#include <stdio.h>
int main () {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    printf("%d\n", a);

    return 0;
}