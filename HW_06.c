#include <stdio.h>
#include <stdlib.h>
#define ll long long
int count = 0;
char *toString(ll b) {
    count = 0;
    char tmp[50];
    while (b > 0) {
        tmp[count++] = (b % 10) + '0';
        b /= 10;
    }
    return tmp;
}

ll countPair(ll a, ll b) {
    count = 0;
    char tmp[50];
    while (b > 0) {
        tmp[count++] = b % 10 + '0';
        b /= 10;
    }
    tmp[count] = '\0';
    int i;
	for (i = 0; i < count; i++) if (tmp[i] != '9') break;
    //printf("%d\n", count);
    ll result;
	if (i == count)
		result = a * count;
	else
		result = a * (count - 1);
	return result;
}

int main() {
	ll n, a, b;
    scanf("%lld", &n);
    while(n--) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", countPair(a, b));
    }
}
