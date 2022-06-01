#include "13490.h"
#include <iostream>
#include <vector>
#include <deque>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma message("GL; HF!")
#endif
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    string s;
    while (cin >> n >> k >> s)
    {
        s.erase(k_unique(s.begin(), s.end(), k), s.end());
        cout << s << '\n';
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        v.erase(k_unique(v.begin(), v.end(), k), v.end());
        for (const int &i : v)
            cout << i << ' ';
        cout << '\n';
        deque<long double> dq(n);
        for (auto &i : dq)
            cin >> i;
        dq.erase(k_unique(dq.begin(), dq.end(), k), dq.end());
        for (const auto &i : dq)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
