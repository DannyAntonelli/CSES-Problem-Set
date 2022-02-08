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
    
    struct Node {
        ll best, best_left, best_right, total;

        Node(ll val) {
            best = best_left = best_right = max(0LL, val);
            total = val;
        }
    };

    Node unit{INT_MIN};
    Node merge(Node left, Node right) {
        Node res = unit;
        res.best = max(left.best_right + right.best_left, max(left.best, right.best));
        res.best_left = max(left.best_left, left.total + right.best_left);
        res.best_right = max(right.best_right, left.best_right + right.total);
        res.total = left.total + right.total;
        return res;
    }

    int n;
    vector<Node> tree;

    SegmentTree(vector<int> data) {
        n = 1;
        while(n < (int) data.size()) n *= 2;
        tree.assign(2 * n, unit);

        for (int i = 0; i < (int) data.size(); i++)
            tree[i + n] = Node{data[i]};

        for (int i = n - 1; i > 0; i--)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    Node get(int i) {
        return query(i, i);
    }

    Node query(int x, int y) {
        Node left = unit, right = unit;
        for (x += n, y += n + 1; x < y; x /= 2, y /= 2) {
            if (x & 1) left = merge(left, tree[x++]);
            if (y & 1) right = merge(tree[--y], right);
        }
        return merge(left, right);
    }

    void update(int i, int v) {
        i += n;
        tree[i] = Node{v};
        for (i /= 2; i > 0; i /= 2)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
};

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vi x(n);
    FOR (i, 0, n) cin >> x[i];

    SegmentTree st{x};

    while (q--) {
        int a, b;
        cin >> a >> b;

        st.update(a - 1, b);
        cout << st.query(0, n - 1).best << "\n";
    }

    return 0;
}