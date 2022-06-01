#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    multiset<int> qu;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "Insert") {
            int tmp;
            cin >> tmp;
            qu.insert(tmp);
        }
        else if (cmd == "Query") {
            int x, k;
            cin >> x >> k;
            auto it = qu.lower_bound(x);
            if (*it < x) {
                cout << "-1" << '\n';
                continue;
            }
            int i;
            for (i = 1; i < k && it != qu.end(); i++, it++) {}
            if (it == qu.end()) cout << "-1" << '\n';
            else cout << *it << '\n';
        }
    }
}