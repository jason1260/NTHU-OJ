#include <bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll, int> ma;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int t, k;
        cin >> t >> k;
        int cnt = 0;
        ll total = 0;
        ma.clear();
        //for (int i = 0; i < total.size(); i++) cout << total[i] << ' ';
        for (int i = 0; i < t; i++) {
            //for (auto it : ma) cout << it.first << ':' << it.second << '\n';
            int tmp; cin >> tmp;
            total += tmp;
            if (total == k) cnt++;
            //cout << "cnt1: " << cnt << '\n';
            if (ma[total - k] != 0) cnt += ma[total - k];
            //cout << "cnt: " << cnt << '\n';
            ma[total]++;
        }
        cout << cnt << '\n';
    }    
}