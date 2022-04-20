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

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vector<vi> graph(n);
    vi in_degree(n, 0);
    FOR (i, 0, m) {
        int u, v;
        cin >> u >> v;
        graph[u-1].PB(v-1);
        ++in_degree[v-1];
    }

    queue<int> q;

    FOR (i, 0, n) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    int index = 0;
    vi order(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order[index++] = u;
        for (int v : graph[u]) {
            --in_degree[v];
            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    if (index != n)
        cout << "IMPOSSIBLE";
    else {
        for (int u : order) {
            cout << u + 1 << " ";
        }
    }

    return 0;
}