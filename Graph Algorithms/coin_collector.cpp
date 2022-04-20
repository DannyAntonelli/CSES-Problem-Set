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

    void init_cond_adj() {
        cond_adj.resize(cc);
        for (int u = 0; u < (int) adj.size(); ++u)
            for (int v : adj[u])
                if (comp[u] != comp[v])
                    cond_adj[comp[u]].push_back(comp[v]);
        for (vi& v : cond_adj) {
            sort(ALL(v));
            v.erase(unique(ALL(v)), v.end());
        }
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

void compute_dp(vector<vi>& adj, vector<ll>& dp, vector<ll>& coins, int u) {
    if (dp[u] != -1) return;
    dp[u] = 0;
    for (int v : adj[u]) {
        compute_dp(adj, dp, coins, v);
        dp[u] = max(dp[u], dp[v]);
    }
    dp[u] += coins[u];
}
 
int main() {
    fast_io();
 
    int n, m;
    cin >> n >> m;

    vi coins(n);
    FOR (i, 0, n) cin >> coins[i];

    vector<vi> adj(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].PB(b);
    }
 
    Kosaraju kosaraju{adj};
    vector<ll> cond_coins(kosaraju.cc);

    FOR (u, 0, n)
        cond_coins[kosaraju.comp[u]] += coins[u];

    vector<ll> dp(kosaraju.cc, -1);
    
    FOR (u, 0, kosaraju.cc)
        compute_dp(kosaraju.cond_adj, dp, cond_coins, u);

    cout << *max_element(ALL(dp));
 
    return 0;
}
