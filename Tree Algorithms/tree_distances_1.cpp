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

vector<vi> adj;
vector<int> height;
vector<vector<pair<int, int>>> dp;

void compute_height(int u=0, int p=-1) {
    for (int v : adj[u]) {
        if (v != p) {
            compute_height(v, u);
            height[u] = max(height[u], 1 + height[v]);
        }
    }
}

void dfs(int u=0, int p=-1) {
    for (int v : adj[u]) {
        if (v != p) {
            if (1 + height[v] >= dp[u][0].S) {
                dp[u][1] = dp[u][0];
                dp[u][0] = {v, 1 + height[v]};
            }
            else if (1 + height[v] >= dp[u][1].S) {
                dp[u][1] = {v, 1 + height[v]};
            }
        }
    }

    if (p != -1) {
        if (dp[p][0].F != u) {
            if (1 + dp[p][0].S >= dp[u][0].S) {
                dp[u][1] = dp[u][0];
                dp[u][0] = {p, 1 + dp[p][0].S};
            }
            else if (1 + dp[p][0].S >= dp[u][1].S) {
                dp[u][1] = {p, 1 + dp[p][0].S};
            }
        }
        else {
            if (1 + dp[p][1].S >= dp[u][0].S) {
                dp[u][1] = dp[u][0];
                dp[u][0] = {p, 1 + dp[p][1].S};
            }
            else if (1 + dp[p][1].S >= dp[u][1].S) {
                dp[u][1] = {p, 1 + dp[p][1].S};
            }
        }
    }

    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
}

int main() {
    fast_io();

    int n;
    cin >> n;

    adj.resize(n);
    FOR (i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].PB(b - 1);
        adj[b - 1].PB(a - 1);
    }
    height.resize(n, 0);
    compute_height();
    dp.resize(n, vector<pair<int, int>>(2, {-1, 0}));
    dfs();

    FOR (i, 0, n) cout << dp[i][0].S << " ";

    return 0;
}