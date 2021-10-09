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

class TreeAncestor {
    vector<vi> lift;
    vi depth;
    int LOG2 = 20;

public:
    TreeAncestor(vi parent) {
        int n = parent.size();

        lift.resize(n, vi(LOG2));
        depth.resize(n, 0);

        FOR (i, 0, n) {
            lift[i][0] = parent[i];
            if (i > 0) depth[i] = 1 + depth[parent[i]];
        }

        FOR (j, 1, LOG2) {
            FOR (i, 0, n) {
                int prev = lift[i][j-1];
                lift[i][j] = lift[prev][j-1];
            }
        }
    }

    int get_kth_ancestor(int u, int k) {
        FOR (i, 0, LOG2) {
            if (k & (1 << i)) u = lift[u][i];
        }
        return u;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int k = depth[u] - depth[v];
        
        u = get_kth_ancestor(u, k);
        if (u == v) return u;

        RFOR (i, LOG2 - 1, -1) {
            if (lift[u][i] != lift[v][i]) {
                u = lift[u][i];
                v = lift[v][i];
            }
        }

        return lift[u][0];
    }
};

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vi parent(n + 1, 0);
    FOR (i, 2, n + 1) cin >> parent[i];

    TreeAncestor tree{parent};

    while (q--) {
        int a, b;
        cin >> a >> b;
        int ancestor = tree.get_lca(a, b);
        cout << ancestor << "\n";
    }

    return 0;
}