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
        ll hash, p;
        Node(char ch) { hash = ch; p = 26; }
        Node() { hash = 0; p = 1; }
    };

    const int MOD = 1000000007;
    Node unit;

    Node merge(Node& a, Node& b) {
        Node res;
        res.p = (a.p * b.p) % MOD;
        res.hash = (a.hash * b.p + b.hash) % MOD;
        return res;
    }

    int n;
    vector<Node> tree;

    SegmentTree(string& data) {
        n = 1;
        while (n < (int) data.size())
            n *= 2;
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

    void update(int i, char v) {
        i += n;
        tree[i] = Node{v};
        for (i /= 2; i > 0; i /= 2)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
};

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    string s1;
    cin >> s1;
    string s2 = s1;
    reverse(ALL(s2));

    SegmentTree tree1{s1}, tree2{s2};

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int k;
            char x;
            cin >> k >> x;

            int i = k - 1;
            int j = n - i - 1;

            tree1.update(i, x);
            tree2.update(j, x);
        }
        else {
            int a, b;
            cin >> a >> b;

            int l1 = a - 1, r1 = b - 1;
            int l2 = n - r1 - 1, r2 = n - l1 - 1;

            if (tree1.query(l1, r1).hash == tree2.query(l2, r2).hash)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}