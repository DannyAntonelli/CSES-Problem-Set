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

class Dsu {
    int num_components;
    vector<int> sz;
    vector<int> parent;

public:

    Dsu(int size) {
        num_components = size;
        sz.resize(size);
        parent.resize(size);

        for (int i = 0; i < size; ++i) {
            sz[i] = 1;
            parent[i] = i;
        }
    }

    int components() {
        return num_components;
    }

    int find(int x) {
        int root = x;

        while (root != parent[root])
            root = parent[root];

        while (x != root) {
            int y = parent[x];
            parent[x] = root;
            x = y;
        }

        return root;
    }

    int size(int x) {
        return sz[find(x)];
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void unify(int x, int y) {
        int root_x = find(x), root_y = find(y);

        if (root_x == root_y)
            return;

        --num_components;
        
        if (sz[root_x] < sz[root_y]) {
            sz[root_y] += sz[root_x];
            parent[root_x] = root_y;
            sz[root_x] = 0;
        }
        else {
            sz[root_x] += sz[root_y];
            parent[root_y] = root_x;
            sz[root_y] = 0;
        }
    }
};

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    Dsu dsu{n};
    int largest = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;

        dsu.unify(a - 1, b - 1);
        largest = max(largest, dsu.size(a - 1));
        cout << dsu.components() << " " << largest << "\n";
    }

    return 0;
}