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
        }

        FOR (j, 1, LOG2) {
            FOR (i, 0, n) {
                int prev = lift[i][j-1];
                lift[i][j] = lift[prev][j-1];
            }
        }
    }

    int get_kth_ancestor(int node, int k) {
        FOR (i, 0, LOG2) {
            if (k & (1 << i)) node = lift[node][i];
        }
        return node;
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
        int x, k;
        cin >> x >> k;
        int ancestor = tree.get_kth_ancestor(x, k);
        cout << (ancestor ? ancestor : -1) << "\n";
    }

    return 0;
}