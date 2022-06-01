#include <bits/stdc++.h>
using namespace std;
vector<int> ta;
map<int, int> ma;
int main() {
    int n, key, cnt = 0;
    cin >> n;
    ta.resize(n);
    for (auto &it : ta) cin >> it;
    cin >> key;
    for (auto it : ta) {
        if (ma[key - it] != 0) {
            cnt += ma[key - it];
        }
        ma[it]++;
    }
    cout << cnt << '\n';
}