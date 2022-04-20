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

struct SegmentTree {
    using Node = int;
    Node unit{INT_MIN}; // s.t. for every x merge(x, unit) = x
    Node merge(Node a, Node b) { return max(a, b); }

    int n_po2;
    vector<Node> tree;

    SegmentTree(vector<int> data) {
        n_po2 = 1;
        while(n_po2 < (int) data.size()) n_po2 *= 2;
        tree.assign(2 * n_po2, unit);

        for (int i = 0; i < (int) data.size(); i++)
            tree[i + n_po2] = Node{data[i]};

        for (int i = n_po2 - 1; i > 0; i--)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    Node get(int i) {
        return query(i, i);
    }

    Node query(int x, int y) {
        Node left = unit, right = unit;
        for (x += n_po2, y += n_po2 + 1; x < y; x /= 2, y /= 2) {
            if (x & 1) left = merge(left, tree[x++]);
            if (y & 1) right = merge(tree[--y], right);
        }
        return merge(left, right);
    }

    void update(int i, int v) {
        i += n_po2;
        tree[i] = Node{v};
        for (i /= 2; i > 0; i /= 2)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
};

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vi h(n);
    FOR (i, 0, n) cin >> h[i];

    SegmentTree st{h};

    while (m--) {
        int q;
        cin >> q;

        int ans = -1;
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int x = st.query(l, mid);

            if (x >= q) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        st.update(ans, st.get(ans) - q);
        cout << ans + 1 << " ";
    }

    return 0;
}