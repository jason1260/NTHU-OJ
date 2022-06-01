#include <stdio.h>
#define ll unsigned long long int
int k, r, l;
ll len_list[60];
ll pow(int n);
char ouq(int n, ll i);
int main() {
    while (scanf("%d %d %d", &k, &l, &r) > 0) {
        for (ll i = l; i <= r; i++) ouq(k, i);
        printf("\n");
    }
}

char ouq(int n, ll i) {
    ll len = pow(n);
    if (i == 0) {printf("O"); return 0;}
    if (i == len >> 1) {printf("u"); return 0;}
    if (i == len - 1) {printf("Q"); return 0;}
    (i < len >> 1) ? ouq(n - 1, i - 1) : ouq(n - 1, i - (len >> 1) - 1);
}

ll pow(int n) {
    if (len_list[n]) return len_list[n];
    ll total = 1;
    total <<= n;
    len_list[n] = total * 3 - 3;
    return total * 3 - 3;
}