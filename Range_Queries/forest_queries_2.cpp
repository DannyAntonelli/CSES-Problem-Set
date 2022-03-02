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

struct FenwickTree2D {
    vector<vector<int>> tree;
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n + 1;
        this->m = m + 1;
        tree.assign(n + 1, vector<int>(m + 1, 0));
    }

    int lsb(int x) {
        return x & (-x);
    }

    void update(int x, int y, int v) {
        for (++x; x < n; x += lsb(x))
            for (int j = y + 1; j < m; j += lsb(j))
                tree[x][j] += v;
    }

    int query(int x, int y) {
        int res = 0;
        for (++x; x > 0; x -= lsb(x))
            for (int j = y + 1; j > 0; j -= lsb(j))
                res += tree[x][j];
        return res;
    }

    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};


int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vector<vi> mat(n, vi(n));
    FenwickTree2D tree{n, n};

    FOR (i, 0, n) {
        FOR (j, 0, n) {
            char c;
            cin >> c;
            if (c == '*') {
                mat[i][j] = 1;
                tree.update(i, j, 1);
            }
        }
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            if (mat[x][y] == 0) {
                mat[x][y] = 1;
                tree.update(x, y, 1);
            }
            else {
                mat[x][y] = 0;
                tree.update(x, y, -1);
            }
        }
        else {
            int y1, x1, y2, x2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1, --y1, --x2, --y2;
            cout << tree.query(x1, y1, x2, y2) << "\n";
        }
    }

    return 0;
}