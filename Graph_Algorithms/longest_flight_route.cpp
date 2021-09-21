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

void dfs(vector<vi> &adj, vi &dist, vi &next, int u=0) {
    if (dist[u] != -1) return;
    
    int res = -3;
    for (int v : adj[u]) {
        dfs(adj, dist, next, v);
        if (dist[v] >= 0 && dist[v] > res) {
            res = dist[v];
            next[u] = v;
        }
    }
    dist[u] = res + 1;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    
    vector<vi> adj(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].PB(b - 1);
    }

    vi dist(n, -1), next(n, -1);
    dist[n - 1] = 0;
    dfs(adj, dist, next);

    if (dist[0] >= 0) {
        cout << dist[0] + 1 << "\n";
        int curr = 0;
        while (curr != n - 1) {
            cout << curr + 1 << " ";
            curr = next[curr];
        }
        cout << n;
    }
    else cout << "IMPOSSIBLE\n";

    return 0;
}