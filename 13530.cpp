#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, int> ma;
vector<ll> lt;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, key, cnt = 0;
    cin >> n;
    lt.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lt[i];
    }
    cin >> key;
    for (int i = 0; i < n; i++) {
        ll tmp = ma[key - lt[i]];
        if (tmp) cnt += tmp;
        for (int j = 0; j < i; j++) {
            ma[lt[i] + lt[j]]++;
        }
    }
    cout << cnt << '\n';
}