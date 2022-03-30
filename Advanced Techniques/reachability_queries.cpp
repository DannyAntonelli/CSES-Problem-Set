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
 
struct Kosaraju {
    vector<vi> adj, radj, cond_adj;
    vector<bool> vis;
    vi comp, order;
    int cc = 0;
 
    void init_radj() {
        int n = adj.size();
        radj.resize(n);
        for (int u = 0; u < n; ++u)
            for (int v : adj[u])
                radj[v].push_back(u);
    }
 
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
 
    void init_cond_adj() {
        vector<vi> complist(cc);
        vi added(cc, -1);
        cond_adj.resize(cc);
 
        for (int i = 0; i < (int) adj.size(); ++i)
            complist[comp[i]].push_back(i);
        for (int i = 0; i < cc; ++i)
            for (int from : complist[i])
                for (int to : adj[from])
                    if (comp[to] != i && added[comp[to]] != i) {
                        cond_adj[i].push_back(comp[to]);
                        added[comp[to]] = i;
                    }
    }
 
    Kosaraju(vector<vi>& g) {
        adj = g;
        init_radj();
        int n = adj.size();
        vis.resize(n);
        comp.resize(n);
        for (int u = 0; u < n; ++u)
            if (!vis[u])
                dfs1(u);
        vis.assign(n, false);
        reverse(ALL(order));
        for (int u : order)
            if (!vis[u])
                dfs2(u), ++cc;
        init_cond_adj();
    }
};
 
constexpr int MAX_N = 50001;
 
void dfs(int u, vector<vi>& adj, vector<bitset<MAX_N>>& dp, vector<bool>& vis) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, dp, vis);
        dp[u] |= dp[v];
    }
}
 
int main() {
    fast_io();
 
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<vi> adj(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].PB(b - 1);
    }
 
    Kosaraju scc{adj};
    vector<bitset<MAX_N>> dp(scc.cc);
    FOR (u, 0, n) dp[scc.comp[u]][u] = 1;

    vector<bool> vis(scc.cc, false);
    FOR (u, 0, scc.cc)
        if (!vis[u])
            dfs(u, scc.cond_adj, dp, vis);
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (dp[scc.comp[a - 1]][b - 1] ? "YES" : "NO") << "\n";
    }
 
    return 0;
}