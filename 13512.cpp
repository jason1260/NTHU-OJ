#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main() {
    int num, k, avail = 0;
    cin >> num >> k;
    //multiset <int> room;
    //for (int i = 0; i < num; i++) room.emplace(i);
    vector <int> is_reserverd;
    for (int i = 0; i < num; i++) is_reserverd.emplace_back(0);
    avail = num;
    while (k--) {
        string command;
        cin >> command;
        if (command == "RESERVE") {
            int want;
            cin >> want;
            if (want > avail) cout << "RESERVE: no vacant rooms\n";
            else {
                cout << "RESERVE: reserve room " ;
                for (int i = is_reserverd.size() - 1; want > 0; i--) {
                    if (!is_reserverd[i]) {
                        is_reserverd[i] = 1;
                        avail--;
                        if (want != 1) cout << i << ',';
                        else cout << i << '\n';
                        want--;
                    }
                }
            }
        }
        else if (command == "UNRESERVE") {
            int key;
            cin >> key;
            if (key >= num || !is_reserverd[key]) cout << "UNRESERVE: " << key << " has not been reserved\n";
            else {
                is_reserverd[key] = 0;
                //room.erase(room.find(key));
                avail++;
                cout << "UNRESERVE: unreserved room " << key << '\n';
            }
        }
    }
}