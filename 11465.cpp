#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<string, deque<int>> ma;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "insert") {
            string n;
            int k;
            cin >> n >> k;
            if (!ma.count(n)) {
                deque<int> tp;
                tp.emplace_back(k);
                ma.insert(pair<string, deque<int>> {n, tp});
            }
            else {
                deque<int> tmp = ma[n];
                tmp.emplace_front(k);
                ma.erase(n);
                ma.insert(pair<string, deque<int>> {n, tmp});
            }
        }
        else if (cmd == "sum") {
            string n;
            cin >> n;
            if (!ma.count(n)) {
                cout << "0\n";
            }
            else {
                int total = 0;
                for (auto &i : ma[n]) {
                    total += i;
                }
                cout << total << '\n';
            }
        }
        else if (cmd == "range") {
            cin >> cmd;
            if (cmd == "output") {
                string l, r;
                cin >> l >> r;
                auto left = ma.lower_bound(l);
                auto right = ma.lower_bound(r);
                while (left != right) {
                    if (left == ma.end()) break;
                    for (auto &i : (*left).second) {
                        cout << i;
                    }
                    if (left != right) cout << ' ';
                    else {cout << '\n'; break;}
                    ++left;
                    if (left == ma.end() || left == right) {
                        if (left != ma.end()) {
                            for (auto &i : (*left).second) {
                                cout << i;
                            }
                        }
                        cout << '\n';
                        break;
                    }
                }
            }
            else if (cmd == "erase") {
                set<string> lt;
                string l, r;
                cin >> l >> r;
                if (l == r) {
                    auto left = ma.find(l);
                    if (left == ma.end()) continue;
                    else lt.insert(l);
                }
                else {
                    auto left = ma.lower_bound(l);
                    auto right = ma.lower_bound(r);
                    while (left != right) {
                        if (left == ma.end()) break;
                        lt.insert((*left).first);
                        if (left != ma.end()) ++left;
                        if (left == right && left != ma.end()) {
                            lt.insert((*left).first);
                            break;
                        }
                    }
                }
                for (auto &i : lt) {
                    //cout << "erase: " << *ma[i].begin() << '\n';
                    ma.erase(i);
                }
            }
        }
        else if (cmd == "output") {
            auto left = ma.begin();
            while (left != ma.end()) {
                for (auto &i : (*left).second) {
                    cout << i;
                }
                ++left;
                if (left == ma.end()) {
                    cout << '\n';
                    break;
                }
                else cout << ' ';
            }
        }
    }
}