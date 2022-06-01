#include "13464.h"
#include <iostream>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma message("GL; HF!")
using namespace std;

int main()
{
    //cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    int n;
    while (cin >> s >> t >> n)
        cout << cmp(s, t) << ' '
             << cmp(s, t, n) << ' '
             << cmp(s, *t.rbegin()) << ' '
             << cmp(*s.begin(), t) << ' '
             << cmp(s, *t.rbegin(), n) << ' '
             << cmp(*s.begin(), t, n) << ' '
             << cmp(*s.rbegin(), *t.begin()) << '\n';
    return 0;
}
