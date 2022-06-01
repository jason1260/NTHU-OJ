#include <bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int len;
        cin >> len;
        map<int, int> ma;
        vector<int> lt;
        for (int i = 0; i < len; i++) {
            int tmp;
            cin >> tmp;
            lt.emplace_back(tmp);
        }
        int l = 0, r = 0, mx = 0;
        while (r < len) {
            while (r < len && !ma[lt[r] * 2] && ((lt[r] & 1) || !ma[lt[r] / 2])) {
                ma[lt[r]]++;
                r++;
            }
            if (mx < r - l) mx = r - l;
            while (r < len && (ma[lt[r] * 2] || !(lt[r] & 1) && ma[lt[r] / 2])) {
                ma[lt[l]]--;
                l++;
            }
        }
        cout << mx << '\n';
    }
}