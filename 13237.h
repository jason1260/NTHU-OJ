#include <iostream>
#include <vector>
#include <list>
#include <set>

using std::vector;
using std::set;
using std::list;
using std::cout;
using std::endl;

using State = vector<int>;
class Crossing {
private:
    vector<int> _items;
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    Crossing(vector<int> np): _items {np} { }
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[6] to indicate the direction of move
    State Go(State s, int wolf, int goat, int cabbage);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ", " << s[2] << ")";
                    cout << "(" << s[3] << ", " << s[4] << ", " << s[5] << ")";
                    if (s[6] == 1) cout << " left\n";
                    else cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};
void Crossing::solve() {
    for (int i = 0; i < 3; i++) _items.emplace_back(0);
    _items.emplace_back(1);
    State cur_state = _items;
    found(cur_state);
    _solutions = _paths;
    /*cout << "------------------\n";
    for (auto path : _paths) {
        for (auto s : path) {
            if (!s.empty()) {
                cout << "(" << s[0] << ", " << s[1] << ", " << s[2] << ")";
                cout << "(" << s[3] << ", " << s[4] << ", " << s[5] << ")";
                if (s[6] == 1) cout << " left\n";
                else cout << " right\n";
            }
        }
        cout << "done" << endl;
    }*/
    /*set<State> tmp = extend(cur_state);
    for (auto &it : tmp) {
        for (auto &j : it) cout << j << ' ';
        cout << '\n';
    }*/
}
set<State> Crossing::extend(State s) {
    set<State> tmp;
    State t = s;
    if (s[6] == 1) {
        t[6] = 0;
        if (valid(t)) tmp.emplace(t);
        t[0] -= 1; t[3] += 1;
        if (t[0] >= 0 && valid(t)) tmp.emplace(t);
        t[0] += 1; t[3] -= 1;
        t[1] -= 1; t[4] += 1;
        if (t[1] >= 0 && valid(t)) tmp.emplace(t);
        t[1] += 1; t[4] -= 1;
        t[2] -= 1; t[5] += 1;
        if (t[2] >= 0 && valid(t)) tmp.emplace(t);
    }
    else {
        t[6] = 1;
        if (valid(t)) tmp.emplace(t);
        t[3] -= 1; t[0] += 1;
        if (t[3] >= 0 && valid(t)) tmp.emplace(t);
        t[3] += 1; t[0] -= 1;
        t[4] -= 1; t[1] += 1;
        if (t[4] >= 0 && valid(t)) tmp.emplace(t);
        t[4] += 1; t[1] -= 1;
        t[5] -= 1; t[2] += 1;
        if (t[5] >= 0 && valid(t)) tmp.emplace(t);
    }
    return tmp;
}
State Crossing::Go(State s, int wolf, int goat, int cabbage) {

}
bool Crossing::valid(State s) {
    return ((((s[0] <= s[1] || !s[1]) && (s[1] <= s[2] || !s[2]) && s[6] == 0) || 
            ((s[3] <= s[4] || !s[4]) && (s[4] <= s[5] || !s[5]) && s[6] == 1)) &&
            _explored.find(s) == _explored.end()) ? true : false;
}
list<State> ppp;
bool Crossing::found(State s) {
    if (s[0] == s[1] && s[1] == s[2] && s[3] == _items[0] && s[4] == _items[1] && s[5] == _items[2] && s[6] == 0) {
        //cout << "Found!\n";
        list<State> tmp = ppp;
        tmp.emplace_back(s);
        /*cout << "Path: ";
        for (auto it : tmp) {
            for (auto j : it) cout << j << ' ';
            cout << '\n';
        }
        cout << "--------\n";*/
        _paths.emplace(tmp);
        return true;
    }
    _explored.emplace(s);
    ppp.emplace_back(s);
    set<State> tmp = extend(s);
    for (auto &it : tmp) {
        found(it);
    }
    _explored.erase(s);
    ppp.pop_back();
    return true;
}