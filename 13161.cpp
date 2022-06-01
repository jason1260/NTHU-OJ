#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string t;
    int c = 0;
    cin >> t;
    for (auto it = t.begin() + 1; it != t.end(); it++) {
        if ((*(it) == *(it - 1) || *(it) == *(it - 2)) && *(it) != 0) {
            *(it) = 0;
            c++;
        }
    }
    cout << c << '\n';
}