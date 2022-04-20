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

struct LazyST {
    using Node = ll;
    using Update = pair<ll, ll>;

    Node unit = Node(0);
    Update no_update = Update(0, 0);

    Node merge(Node left, Node right) { 
        return left + right;
    }

    Node update_node(Node a, Update upd, int l, int r) {
        if (upd.S) a = upd.S * (r - l + 1);
        else a += upd.F * (r - l + 1);
        return a;
    }

    Update combine_updates(Update prev, Update upd) {
        Update res = no_update;
        if (upd.S) res.S = upd.S;
        else if (prev.S) res.S = prev.S + upd.F;
        else res.F = prev.F + upd.F; 
        return res;
    }

    int n;
    vector<Node> st;
    vector<Update> lz;

    LazyST(const vector<int>& data) {
        n = 1;
        while (n < (int) data.size())
            n *= 2;
        st.assign(2 * n, unit);
        lz.assign(n, no_update);

        for (int i = 0; i < (int) data.size(); ++i)
            st[i + n] = Node{data[i]};

        for (int i = n - 1; i > 0; --i)
            st[i] = merge(st[2 * i], st[2 * i + 1]);
    }

    void push(int u, int l, int r) {
        if (u >= n || lz[u] == no_update) return;

        st[2 * u] = update_node(st[2 * u], lz[u], l, (l + r) / 2);
        st[2 * u + 1] = update_node(st[2 * u + 1], lz[u], (l + r) / 2 + 1, r);
        
        if (2 * u < n) {
            lz[2 * u] = combine_updates(lz[2 * u], lz[u]);
            lz[2 * u + 1] = combine_updates(lz[2 * u + 1], lz[u]);
        }

        lz[u] = no_update;
    }

    Node query(int u, int l, int r, int x, int y) {
        if (r < x || l > y) return unit;
        if (l >= x && r <= y) return st[u];

        push(u, l, r);
        return merge(
            query(2 * u, l, (l + r) / 2, x, y),
            query(2 * u + 1, (l + r) / 2 + 1, r, x, y)
        );
    }

    void update(int u, int l, int r, int x, int y, Update v) {
        if (r < x || l > y) return;

        if (l >= x && r <= y) {
            st[u] = update_node(st[u], v, l, r);
            if(u < n)
                lz[u] = combine_updates(lz[u], v);
        }
        else {
            push(u, l, r);
            update(2 * u, l, (l + r) / 2, x, y, v);
            update(2 * u + 1, (l + r) / 2 + 1, r, x, y, v);
            st[u] = update_node(merge(st[2 * u], st[2 * u + 1]), lz[u], l, r);
        }
    }

    Node query(int x, int y) { 
        return query(1, 0, n-1, x, y);
    }

    void update(int x, int y, Update v) {
        return update(1, 0, n-1, x, y, v);
    }
};

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vi v(n);
    FOR (i, 0, n) cin >> v[i];

    LazyST st{v};

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        --a, --b;

        if (t == 1) {
            int x;
            cin >> x;
            st.update(a, b, {x, 0});
        }
        else if (t == 2) {
            int x;
            cin >> x;
            st.update(a, b, {0, x});
        }
        else {
            cout << st.query(a, b) << "\n";
        }
    }

    return 0;
}