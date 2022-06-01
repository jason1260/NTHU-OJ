#include <iostream>
#include <string>
#define mg 880301
#define ll long long
using namespace std;
class special_power{
public:
    int n;
    special_power(int n);
    int fpow(int x);
    int fpow(int x, int m);
    int fpow();
    string fpow(string s);
    string fpow(string s, int m);
};

special_power::special_power(int n) {
    this->n = n;
}

int special_power::fpow(int x) {
    ll ans = 1;
    x %= mg;
    for (int i = 0; i < n; i++) {
        ans *= x;
        if (ans >= mg) ans %= mg;
    }
    return ans % mg;
}

int special_power::fpow(int x, int m) {
    ll ans = 1;
    x %= m;
    for (int i = 0; i < n; i++) {
        ans *= x;
        if (ans >= m) ans %= m;
    }
    return ans % m;
}

int special_power::fpow() {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans <<= 1;
        if (ans >= mg) ans %= mg;
    }
    return ans % mg;
}

string special_power::fpow(string s) {
    string ans;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < n; j++) {
            ans += s[i];
        }
    }
    return ans;
}

string special_power::fpow(string s, int m) {
    string ans;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (ans.size() < m) ans += s[i];
        }
    }
    return ans;
}