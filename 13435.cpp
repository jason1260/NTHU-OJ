#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> list[20010];
int visit[20010], len = 0, vertex = 0;
void dfs(int v, int d) {
    if (d > len) {len = d; vertex = v;}
    for (int i = 0; i < list[v].size(); i++) {
        if (!visit[list[v][i]]) {
            //cout << "visited: " << list[v][i] << '\n';
            visit[list[v][i]] = 1;
            dfs(list[v][i], d + 1);
            visit[list[v][i]] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--) {
        len = 0, vertex = 0;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++) list[i].clear();
        for (int i = t; i > 1; i--) {
            int a, b;
            cin >> a >> b;
            list[a].emplace_back(b);
            list[b].emplace_back(a);
        }
        int enter = 0;
        for (int i = 1; i <= t; i++) if (list[i].size()) {enter = i; break;}
        visit[enter] = 1;
        dfs(enter, 0);
        visit[enter] = 0;
        //cout << "vertex: " << vertex << "\n";
        len = 0;
        int tmp = vertex;
        visit[tmp] = 1;
        dfs(vertex, 0);
        visit[tmp] = 0;
        cout << len << "\n";
    }
}