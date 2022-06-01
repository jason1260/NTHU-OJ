#include <stdio.h>
long long int pow(int num, int k);
int main () {
    int num;
    long long int ans = 0;
    char t[9];
    scanf("%d", &num);
    scanf("%s", t);
    for (int i = 0; i < 8; i++) {
        if (t[7 - i] < 60) ans += pow(num, i) * (t[7 - i] - '0');
        else ans += pow(num, i) * (t[7 - i] - 'A' + 10);
        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);

    return 0;
}

long long int pow (int num, int k) {
    long long int tmp = 1;
    for (int i = 0; i < k; i++) tmp *= num;
    return tmp;
} 