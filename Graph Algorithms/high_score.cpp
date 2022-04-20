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

void dfs(vector<vi> &graph, vector<bool> &vis, int u) {
    vis[u] = true;
    for (int v : graph[u]) {
        if (!vis[v]) dfs(graph, vis, v);
    }
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    
    vector<vi> edges(m, vi(3));
    vector<vi> inverse_graph(n);
    FOR (i, 0, m) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        --edges[i][0]; --edges[i][1]; edges[i][2] = -edges[i][2];
        inverse_graph[edges[i][1]].PB(edges[i][0]);
    }

    const ll INF = LLONG_MAX;
    vector<ll> distance(n, INF);
    distance[0] = 0;

    FOR (i, 0, n-1) {
        FOR (j, 0, m) {
            int u = edges[j][0], v = edges[j][1];
            ll w = edges[j][2];
            if (distance[u] != INF) {
                distance[v] = min(distance[v], distance[u] + w);
            }
        }
    }

    set<int> possible_cycles;
    FOR (i, 0, m) {
        int u = edges[i][0], v = edges[i][1];
        ll w = edges[i][2];
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            possible_cycles.insert(v);
        }
    }
    
    vector<bool> vis(n, false);
    dfs(inverse_graph, vis, 0);
    dfs(inverse_graph, vis, n-1);

    for (int u : possible_cycles) {
        if (vis[u]) {
            cout << "-1";
            return 0;
        }
    }
    cout << -distance[n-1];

    return 0;
}