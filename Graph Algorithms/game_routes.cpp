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

const int MOD = 1000000007;

int dfs(vector<vi>& adj, vi& dp, int u=0, int p=-1) {
    if (dp[u] != -1) return dp[u];
    dp[u] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dp[u] += dfs(adj, dp, v, u);
        dp[u] %= MOD;
    }

    return dp[u];
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

    vi dp(n, -1);
    dp[n - 1] = 1;

    cout << dfs(adj, dp);

    return 0;
}