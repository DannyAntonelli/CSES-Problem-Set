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

constexpr int MAX_N = 50001;

void dfs(int u, vector<vi>& adj, vector<bitset<MAX_N>>& dp, vi& ans) {
    if (ans[u] != 0) return;
    for (int v : adj[u]) {
        dfs(v, adj, dp, ans);
        dp[u] |= dp[v];
    }
    ans[u] = dp[u].count();
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

    vector<bitset<MAX_N>> dp(n);
    vector<bool> vis(n, false);

    FOR (u, 0, n) dp[u][u] = 1;

    vi ans(n);
    FOR (u, 0, n) {
        dfs(u, adj, dp, ans);
        cout << ans[u] << " ";
    }

    return 0;
}
