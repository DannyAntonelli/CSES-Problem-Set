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

void dfs(vector<vi>& adj, vi& sz, int u=0, int p=-1) {
    for (int v : adj[u]) if (v != p) {
        dfs(adj, sz, v, u);
        sz[u] += sz[v];
    }
}

int get_centroid(vector<vi>& adj, vi& sz, int u=0, int p=-1) {
    int n = adj.size();
    for (int v : adj[u]) if (v != p && 2 * sz[v] > n)
        return get_centroid(adj, sz, v, u);
    return u;
}

int main() {
    fast_io();
 
	int n; cin >> n;
    vector<vi> adj(n);
    FOR (i, 0, n - 1) {
        int a, b; cin >> a >> b;
        adj[a - 1].PB(b - 1);
        adj[b - 1].PB(a - 1);
    }

    vi sz(n, 1);
    dfs(adj, sz);

    cout << get_centroid(adj, sz) + 1;
 
    return 0;
}