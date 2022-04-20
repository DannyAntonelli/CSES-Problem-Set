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

vector<vector<int>> adj;
vi sz;
vi dist;
vector<ll> ans;
 
void comp_size(int u=0, int p=-1) {
    for (int v : adj[u]) {
        if (v != p) {
            comp_size(v, u);
            sz[u] += sz[v];
        }
    }
}
 
void dfs(int u, int p) {
    int n = adj.size();
    ans[u] = ans[p] + n - 2 * sz[u];

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    fast_io();

    int n;
    cin >> n;
    
    adj.resize(n);
    FOR (i, 0, n - 1) {
        int u, v; cin >> u >> v;
        adj[u - 1].PB(v - 1);
        adj[v - 1].PB(u - 1);
    }

    sz.resize(n, 1);
    dist.resize(n, 0);
    ans.resize(n, 0);
    comp_size();
 
    queue<pi> q;
    q.push({0, -1});

    while (!q.empty()) {
        pi p = q.front(); q.pop();

        for (int u : adj[p.F]) {
            if (u != p.S) {
                dist[u] = dist[p.F] + 1;
                q.push({u, p.F});
            }
        }
    }
 
    ll tot = 0;
    FOR (i, 0, n) tot += dist[i];
    ans[0] = tot;
 
    for (int u : adj[0]) dfs(u, 0);

    for (ll x : ans) cout << x << " ";

    return 0;
}