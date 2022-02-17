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

    vector<vi> roads(m);
    FOR (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[i] = {c, a - 1, b - 1};
    }
    sort(ALL(roads));

    Dsu dsu{n};
    ll cost = 0;

    for (vi road : roads) {
        if (!dsu.connected(road[1], road[2])) {
            dsu.unify(road[1], road[2]);
            cost += road[0];
        }
    }

    if (dsu.components() == 1) cout << cost;
    else cout << "IMPOSSIBLE\n";

    return 0;
}