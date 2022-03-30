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

void merge(set<int>& small, set<int>& large) {
    for (int x : small) large.insert(x);
}

void dfs(vector<vi>& adj, vi& ans, vector<set<int>>& colors, vi& c, int u=0, int p=-1) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(adj, ans, colors, c, v, u);
        if (colors[u].size() < colors[v].size())
            swap(colors[u], colors[v]);
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        merge(colors[v], colors[u]);
    }

    colors[u].insert(c[u]);
    ans[u] = colors[u].size();
}
 
int main() {
    fast_io();

    int n;
    cin >> n;

    vi c(n);
    FOR (i, 0, n) cin >> c[i];

    vector<vi> adj(n);
    FOR (_, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    vi ans(n);
    vector<set<int>> colors(n);

    dfs(adj, ans, colors, c);

    FOR (i, 0, n)
        cout << ans[i] << " ";

    return 0;
}
