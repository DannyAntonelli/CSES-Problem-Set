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

struct Bridges {
	vector<pair<int, int>> edges;
	vector<bool> vis;
	vi tin, low;
	int t;

	void dfs(vector<vi>& adj, int u, int p=-1) {
		vis[u] = true;
		tin[u] = low[u] = t++;

		for (int v : adj[u]) {
			if (v == p) continue;
			if (vis[v]) low[u] = min(low[u], tin[v]);
			else {
				dfs(adj, v, u);
				low[u] = min(low[u], low[v]);
				if (low[v] > tin[u]) edges.push_back({u, v});
			}
		}
	}

	Bridges(vector<vi>& adj) {
		int n = adj.size();
		t = 0;
		vis.resize(n, false);
		tin.resize(n, -1);
		low.resize(n, -1);

		for (int u = 0; u < n; ++u)
			if (!vis[u])
				dfs(adj, u);
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

    Bridges bridges{adj};

    cout << bridges.edges.size() << "\n";
    for (pi p : bridges.edges)
        cout << p.F + 1 << " " << p.S + 1 << "\n";

    return 0;
}
