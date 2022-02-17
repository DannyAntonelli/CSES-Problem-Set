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

void dfs(vector<vi>& adj, vector<bool>& visited, int u=0) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(adj, visited, v);
    }
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vector<vi> adj(n), rev(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].PB(b);
        rev[b].PB(a);
    }

    vector<bool> visited(n);
    dfs(adj, visited);
    
    FOR (i, 0, n) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << "1 " << i + 1;
            return 0;
        }
    }
    
    FOR (i, 0, n) visited[i] = false;
    dfs(rev, visited);

    FOR (i, 0, n) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i + 1 << " 1";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}