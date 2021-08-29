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

void solve(vector<vi> &adj, vector<vi> &dp, int u, int p) {
    if (u != 0 && adj[u].size() == 1) return;

    int child1 = 0, child2 = 0;
    for (int v : adj[u]) {
        if (v != p) {
            solve(adj, dp, v, u);
            dp[u][0] = max(dp[u][0], 1 + dp[v][0]);
            if (dp[v][0] > child1) {
                child2 = child1;
                child1 = dp[v][0];
            }
        }
    }

    dp[u][1] = (int)(adj[u].size() > 0) + (int)(adj[u].size() > 1) + child1 + child2;
}

int main() {
    fast_io();

    int n;
    cin >> n;
    vector<vi> adj(n);
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].PB(b-1);
        adj[b-1].PB(a-1);
    }

    vector<vi> dp(n, vi(2, 0));
    solve(adj, dp, 0, -1);

    int res = 0;
    FOR (i, 0, n) {
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    cout << res;

    return 0;
}