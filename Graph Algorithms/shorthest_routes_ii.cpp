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

    int n, m, q;
    cin >> n >> m >> q;
    const ll INF = LLONG_MAX;
    vector<vector<ll>> graph(n, vector<ll>(n, INF));

    FOR (i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        if (graph[a][b] != INF) {
            graph[a][b] = min(graph[a][b], (ll)c);
            graph[b][a] = graph[a][b];
        }
        else {
            graph[a][b] = c;
            graph[b][a] = c;
        }
    }

    FOR (i, 0, n) graph[i][i] = 0;

    vector<vector<ll>> distance(n, vector<ll>(n));

    FOR (i, 0, n) {
        FOR (j, 0, n) 
            distance[i][j] = graph[i][j];
    }

    FOR (k, 0, n) {
        FOR (i, 0, n) {
            FOR (j, 0, n) {
                if (distance[i][k] != INF && distance[k][j] != INF)
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << (distance[a][b] == INF ? -1 : distance[a][b]) << "\n";
    }

    return 0;
}