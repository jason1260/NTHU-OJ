#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int len, mx = 0, l = 0, r = 0;
        cin >> len;
        vector<int> lt;
        lt.resize(len);
        for (auto &i : lt) cin >> i;
        unordered_map<int, bool> ma;
        while (r < len) {
            while (r < len && !ma[lt[r]]) {
                ma[lt[r++]] = true;
            }
            if (mx < r - l) mx = r - l;
            while (r < len && ma[lt[r]]) {
                ma[lt[l++]] = false;
            }
        }
        cout << mx << '\n';
    }
}