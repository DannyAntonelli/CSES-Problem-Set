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

vector<vi> adj, radj;
vector<bool> vis;
vi comp, order;
int cc = 1;

void dfs1(int u) {
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp[u] = cc;

    for (int v : radj[u])
        if (!vis[v])
            dfs2(v);
}

void korasaju() {
    int n = adj.size();
    vis.assign(n, false);

    for (int u = 0; u < n; ++u)
        if (!vis[u])
            dfs1(u);

    vis.assign(n, false);
    reverse(ALL(order));

    for (int u : order)
        if (!vis[u])
            dfs2(u), ++cc;

    --cc;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    adj.resize(n);
    radj.resize(n);
    vis.resize(n);
    comp.resize(n);

    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].PB(b);
        radj[b].PB(a);
    }

    korasaju();
    cout << cc << "\n";
    for (int c : comp) cout << c << " ";

    return 0;
}