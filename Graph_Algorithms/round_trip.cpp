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
 
bool dfs(int curr, vector<vi> &graph, vector<bool> &visited, vi &path) {
    path.PB(curr);
    int n = path.size();

    if (visited[curr]) {
        n = path.size();
        int x = path[n-1];
 
        if (n >= 4 && path[n-2] != x && path[n-3] != x)
            return true;
 
        path.pop_back();
        return false;
    }
    visited[curr] = true;
 
    for (int x : graph[curr]) {
        if (dfs(x, graph, visited, path)) return true;
    }
 
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
        graph[b-1].PB(a-1);
    }
    
    vector<bool> visited(n);
    vi path;
    
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