#ifndef FUNCTION_H_
#define FUNCTION_H_
#define ll long long
#include <cstdlib>
#include <stddef.h>
#include <iostream>
using namespace std;
class point {
    public:
    ll val, people, type;
    point() : val(0), people(0), type(0) {};
    point(ll v, ll p, ll t) : val(v), people(p), type(t) {};
    bool operator< (const point& p) {
        return (val != p.val) ? val < p.val : type < p.type;
    }
};
class group {
    public:
    group() : num(0), arr(0), lev(0), place("") {};
    group(ll p, ll a, ll l, string pl) : num(p), arr(a), lev(l), place(pl) {};
    bool operator< (const group &p) {
        return (arr != p.arr) ? arr < p.arr : lev > p.lev;
    }
    string place;
    ll num;
    ll arr;
    ll lev;
};
ll n;
pair<ll, ll> traff_mx = {0, 0};
// TODO: Implement the sorting algorithm
template < class T >
void mSort(T arg[], int st, int ed) {
    if (st >= ed) return;
    T arr[ed + 5];
    int mid = ((ed - st) >> 1) + st;
    int st1 = st, ed1 = mid;
    int st2 = mid + 1, ed2 = ed;
    mSort(arg, st1, ed1);
    mSort(arg, st2, ed2);
    int k = st;
    while (st1 <= ed1 && st2 <= ed2) arr[k++] = arg[st1] < arg[st2] ? arg[st1++] : arg[st2++];
    while (st1 <= ed1) arr[k++] = arg[st1++];
    while (st2 <= ed2) arr[k++] = arg[st2++];
    for (k = st; k <= ed; k++) arg[k] = arr[k];
}
ll find_traffic(point* pt, int t) {
    ll total = 0;
    for (ll i = 0; i < 2 * n; i++) {
        if (pt[i].val > t) break;
        if (!pt[i].type) total += pt[i].people;
        else total -= pt[i].people;
    }
    return total;
}
pair<ll, ll> max_traffic(point* pt) {
    ll last = pt[0].val, total = 0; pair<ll, ll> mx = {0, 0};
    for (ll i = 0; i < 2 * n; i++) {
        if (pt[i].val != last) {
            if (total > mx.second) {
                mx.second = total;
                mx.first = last;
                last = pt[i].val;
            }
            else last = pt[i].val;
        }
        if (!pt[i].type) {
            total += pt[i].people;
        }
        else {
            total -= pt[i].people;
        }
    }
    return mx;
}
void solve() {
    ll k, store_cnt = 0;
    cin >> n;
    group student[n];
    string storelist[n];
    point timelist[2 * n + 5];
    for (ll i = 0; i < n; i++) {
        ll p, a, l, flag = 0;
        string pl;
        cin >> p >> a >> l >> pl;
        student[i] = group(p, a, l, pl);
        for (ll j = 0; j < store_cnt; j++) {
            if (storelist[j] == pl) {flag = 1; break;}
        }
        if (!flag) storelist[store_cnt++] = pl;
        timelist[2 * i] = point(a, p, 0);
        timelist[2 * i + 1] = point(l, p, 1);
    }
    mSort(student, 0, n - 1);
    mSort(timelist, 0, 2 * n - 1);
    mSort(storelist, 0, store_cnt - 1);
    pair<ll, ll> mx_trf = max_traffic(timelist);
    cin >> k;
    while (k--) {
        string cmd;
        cin >> cmd;
        if (cmd == "TIME_ARRIVE") {
            int tm;
            cin >> tm;
            cout << student[tm - 1].arr << '\n';
        }
        else if (cmd == "TRAFFIC_AT") {
            int tm;
            cin >> tm;
            cout << find_traffic(timelist, tm) << '\n';
        }
        else if (cmd == "MAX_TRAFFIC") {
            cout << mx_trf.first << ' ' << mx_trf.second << '\n';
        }
        else if (cmd == "STORE_LIST") {
            for (int i = 0; i < store_cnt; i++) {
                cout << storelist[i];
                (i == store_cnt - 1) ? cout << '\n' : cout << ' ';
            }
        }
    }
}




// The codes below prevent you from using built-in sorting function and from importing C++ containers.
// Nothing needs to be implemented below.
// Do not modify the codes below.

void qsort(void* , std::size_t , std::size_t , void*);

template <class RandomAccessIterator>
void sort (RandomAccessIterator , RandomAccessIterator );

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator , RandomAccessIterator , Compare );

#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif
