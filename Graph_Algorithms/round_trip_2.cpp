#include <bits/stdc++.h>
 
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i > (b); --i)
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
#define MP make_pair
 
using namespace std;
using ll = long long;
using ld = long double;
 
typedef vector<int> vi;
typedef pair<int, int> pi;
 
void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
bool dfs(int curr, vector<vi> &graph, vi &visited, vi &path) {
    path.PB(curr);

    if (visited[curr] == 2) return true;
    else if (visited[curr] == 1) {
        path.pop_back();
        return false;
    }
    visited[curr] = 2;
 
    for (int x : graph[curr])
        if (dfs(x, graph, visited, path)) return true;

    visited[curr] = 1;
    path.pop_back();
    return false;
}
 
int main() {
    fast_io();
 
    int n, m;
    cin >> n >> m;
 
    vector<vi> graph(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        graph[a-1].PB(b-1);
    }
    
    vi visited(n), path;
    
    FOR (i, 0, n) {
        if (dfs(i, graph, visited, path)) {
            int n = path.size();
            int x = path[n-1];
            int i = 0;
            while (path[i] != x) {
                ++i;
            }
            cout << n - i << "\n";
            FOR (j, i, n) {
                cout << path[j] + 1 << " ";
            }
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE";
    return 0;
}