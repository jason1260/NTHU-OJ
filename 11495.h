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
int min_sz = INT32_MAX;
class Crossing
{
private:
    vector<int> _npeople;  // how many missionaries and cannibals
                           // we use vector<int> as a tuple (int, int)
                           // the first integer indicate the number of missionaries
                           // the second integer indicates the number of cannibals
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    // specify the numbers of missionaries and cannibals
    Crossing(vector<int> np): _npeople {np} { }
    // the starting porint of your implementation
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[4] to indicate the direction of move
    State Go(State s, int missionary, int cannibal);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ")";
                    cout << "(" << s[2] << ", " << s[3] << ")";
                    if (s[4]==1) cout << " left\n";
                    else cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};
State Crossing::Go(State s, int missionary, int cannibal) {}
void Crossing::solve() {
    for (int i = 0; i < 2; i++) _npeople.emplace_back(0);
    _npeople.emplace_back(1);
    State cur = _npeople;
    /*set<State> tmp = extend(cur);
    for (auto &it : tmp) {
        for (auto &j : it) cout << j << ' ';
        cout << '\n';
    }*/
    found(cur);
    _solutions = _paths;
    for (auto &it : _solutions) {
        if (it.size() > min_sz) {
            _solutions.erase(it);
        }
    }
}
set<State> Crossing::extend(State s) {
    set<State> tmp;
    State t = s;
    if (s[4] == 1) {
        t[4] = 0;
        t[0] -= 1; t[2] += 1;
        if (valid(t)) tmp.emplace(t);
        t[0] -= 1; t[2] += 1;
        if (valid(t)) tmp.emplace(t);
        t[0] += 2; t[2] -= 2;
        t[1] -= 1; t[3] += 1;
        if (valid(t)) tmp.emplace(t);
        t[1] -= 1; t[3] += 1;
        if (valid(t)) tmp.emplace(t);
        t[1] += 1; t[3] -= 1; t[0] -= 1; t[2] += 1;
        if (valid(t)) tmp.emplace(t);
    }
    else {
        t[4] = 1;
        t[2] -= 1; t[0] += 1;
        if (t[2] >= 0 && valid(t)) tmp.emplace(t);
        t[2] -= 1; t[0] += 1;
        if (t[2] >= 0 && valid(t)) tmp.emplace(t);
        t[2] += 2; t[0] -= 2;
        t[3] -= 1; t[1] += 1;
        if (t[3] >= 0 && valid(t)) tmp.emplace(t);
        t[3] -= 1; t[1] += 1;
        if (t[3] >= 0 && valid(t)) tmp.emplace(t);
        t[3] += 1; t[1] -= 1; t[2] -= 1; t[0] += 1;
        if (t[2] >= 0 && t[3] >= 0 && valid(t)) tmp.emplace(t);
    }
    return tmp;
}
bool Crossing::valid(State s) {
    return ((s[0] >= s[1] || !s[0]) && (s[2] >= s[3] || !s[2]) &&
            _explored.find(s) == _explored.end() && s[0] >= 0 &&
            s[1] >= 0 && s[2] >= 0 && s[3] >= 0) ? true : false;
}
list<State> ppp;
bool Crossing::found(State s) {
    if (s[0] == 0 && s[1] == 0 && s[2] == _npeople[0] && s[3] == _npeople[1] && s[4] == 0) {
        //cout << "Found!\n";
        if (ppp.size() + 1 > min_sz) return false;
        list<State> tmp = ppp;
        tmp.emplace_back(s);
        _paths.emplace(tmp);
        min_sz = std::min(min_sz, int(tmp.size()));
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