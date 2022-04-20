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

const ll INF = 1e18;
vector<vector<int>> edges;
vector<ll> dist;
vi par;

int bellman_ford() {
    int n = dist.size();
    bool relaxed = true;

    for (int i = 0; i < n - 1 && relaxed; ++i) {
        relaxed = false;
        for (vector<int> e : edges) {
            int start = e[0], end = e[1];
            long long weight = (long long)e[2];
            if (dist[start] + weight < dist[end]) {
                dist[end] = dist[start] + weight;
                par[end] = start;
                relaxed = true;
            }
        }
    }

    for (int i = 0; i < n - 1 && relaxed; ++i) {
        relaxed = false;
        for (vector<int> e : edges) {
            int start = e[0], end = e[1];
            long long weight = (long long)e[2];
            if (dist[start] != INF && dist[start] + weight < dist[end]) {
                par[end] = start;
                return end;
            }
        }
    }

    return -1;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    edges.resize(m);
    dist.resize(n, INF);
    dist[0] = 0;
    par.resize(n, -1);

    FOR (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, c};
    }

    int u = bellman_ford();

    if (u == -1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    FOR (i, 0, n) {
        u = par[u];
    }
    vi path(1, u);

    for (int v = par[u]; v != u; v = par[v]) {
        path.PB(v);
    }
    path.PB(path[0]);

    reverse(ALL(path));
    for (int node : path) {
        cout << node + 1 << " ";
    }

    return 0;
}