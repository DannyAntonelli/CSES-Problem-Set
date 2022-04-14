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

struct ArticulationPoints {
    vector<bool> is_ap, vis;
    vi tin, low;
    int t;

    int dfs(vector<vi>& adj, int u, int p=-1) {
        vis[u] = true;
        tin[u] = low[u] = t++;
        int c = 0;

        for (int v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) low[u] = min(low[u], tin[v]);
            else {
                ++c;
                dfs(adj, v, u);
                low[u] = min(low[u], low[v]);
                if (p != -1 && low[v] >= tin[u]) is_ap[u] = 1;
            }
        }

        return c;
    }

    ArticulationPoints(vector<vi>& adj) {
        int n = adj.size();
        t = 0;
        is_ap.resize(n, false);
        vis.resize(n, false);
        tin.resize(n, -1);
        low.resize(n, -1);

        for (int u = 0; u < n; ++u)
            if (!vis[u])
                is_ap[u] = dfs(adj, u) > 1;
    }
};

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    ArticulationPoints articulation_points{adj};
    vi ans;

    FOR (i, 0, n)
        if (articulation_points.is_ap[i])
            ans.PB(i + 1);

    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";

    return 0;
}
