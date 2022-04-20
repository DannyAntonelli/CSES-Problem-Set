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
    vector<vector<int>> lift;
    vector<int> depth;
    int dim;

    int ipow(int base, int exp) {
        int result = 1;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) {
                result *= base;
            }
            base *= base;
        }
        return result;
    }

    void dfs(vector<int> &parent, vector<vector<int>> &adj, int u=0, int p=0, int d=0) {
        parent[u] = p;
        depth[u] = d;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(parent, adj, v, u, d + 1);
            }
        }
    }

    pair<int, int> lca_and_distance(int u, int v) {
        int distance = 0;

        if (depth[u] < depth[v]) swap(u, v);
        int k = depth[u] - depth[v];
        distance += k;
        
        u = get_kth_ancestor(u, k);
        if (u == v) {
            return make_pair(u, distance);
        }

        for (int i = dim - 1; i >= 0; --i) {
            if (lift[u][i] != lift[v][i]) {
                distance += 2 * ipow(2, i);
                u = lift[u][i];
                v = lift[v][i];
            }
        }

        return make_pair(lift[u][0], distance + 2);
    }

public:

    TreeAncestor(vector<vector<int>> &adj, int root=0) {
        int n = adj.size();
        depth.resize(n, 0);

        vector<int> parent(n, 0);
        dfs(parent, adj, root);

        dim = 0;
        while (n >= (1 << dim)) {
            ++dim;
        }

        lift.resize(n, vector<int>(dim));

        for (int i = 0; i < n; ++i) {
            lift[i][0] = parent[i];
        }

        for (int j = 1; j < dim; ++j) {
            for (int i = 0; i < n; ++i) {
                int prev = lift[i][j-1];
                lift[i][j] = lift[prev][j-1];
            }
        }
    }

    int get_depth(int u) {
        return depth[u];
    }

    int get_kth_ancestor(int u, int k) {
        if (k > depth[u]) {
            return -1;
        }

        for (int i = 0; i < dim; ++i) {
            if (k & (1 << i)) {
                u = lift[u][i];
            }
        }

        return u;
    }

    int get_lca(int u, int v) {
        return lca_and_distance(u, v).first;
    }

    int get_distance(int u, int v) {
        return lca_and_distance(u, v).second;
    }
};

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vector<vi> adj(n);
    FOR (i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].PB(b-1);
        adj[b-1].PB(a-1);
    }

    TreeAncestor tree{adj};

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << tree.get_distance(a - 1, b - 1) << "\n";
    }

    return 0;
}