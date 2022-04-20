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

vector<pair<ll, ll>> dijkstra(vector<vector<pi>> &adj) {
    const ll INF = LLONG_MAX;
    int n = adj.size();
    vector<pair<ll, ll>> distance(n, {INF, INF});
    distance[0] = {0, 0};
    set<pair<pair<ll, ll>, int>> s{{{0, 0}, 0}};

    while (!s.empty()) {
        int u = s.begin()->S;
        s.erase(s.begin());

        for (pi p : adj[u]) {
            int v = p.F, dist = p.S;
            pair<ll, ll> temp = distance[v];
            bool flag = false;

            if (distance[u].F + dist < distance[v].F) {
                distance[v].F = distance[u].F + dist;
                flag = true;
            }

            if (distance[u].S + dist < distance[v].S) {
                distance[v].S = distance[u].S + dist;
                flag = true;
            }

            if (distance[u].F + dist / 2 < distance[v].S) {
                distance[v].S = distance[u].F + dist / 2;
                flag = true;
            }

            if (flag) {
                s.erase({temp, v});
                s.insert({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vector<vector<pi>> adj(n);
    FOR (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].PB({b - 1, c});
    }

    vector<pair<ll, ll>> distance = dijkstra(adj);
    cout << distance[n - 1].S;

    return 0;
}