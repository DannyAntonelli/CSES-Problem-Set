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

set<pi> get_neighbors(int i, int j, vector<vector<char>> &g) {
    int n = g.size(), m = g[0].size();
    int di[] = {0, 0, -1, 1};
    int dj[] = {-1, 1, 0, 0};
    set<pi> res;
    FOR (k, 0, 4) {
        int x = i + di[k], y = j + dj[k];
        if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#') {
            res.insert({x, y});
        }
    }
    return res;
}

bool is_border(int i, int j, int n, int m) {
    return i == 0 || j == 0 || i == n-1 || j == m-1;
}

int main() {
    fast_io();

    auto comp = [](pair<int, pi> a, pair<int, pi> b) {
        if (a.F != b.F) return a.F < b.F;
        else return a.S < b.S;
    };
    set<pair<int, pi>, decltype(comp)> s(comp);
    
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    pi start = {0, 0};
    const int INF = INT_MAX;
    vector<vi> monsters(n, vi(m, INF));

    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                start = {i, j};
            }
            else if (g[i][j] == 'M') {
                s.insert({0, {i, j}});
                monsters[i][j] = 0;
            }
        }
    }

    while (!s.empty()) {
        auto x = *s.begin(); s.erase(s.begin());
        int dist = x.F;
        pi point = x.S;
        for (pi n : get_neighbors(point.F, point.S, g)) {
            if (monsters[n.F][n.S] == INF) {
                monsters[n.F][n.S] = dist + 1;
                s.insert({dist+1, n});
            }
        }
    }

    pi UNVISITED = {-1, 0}, FAIL = {0, -1};
    vector<vector<pi>> parent(n, vector<pi>(m, UNVISITED));
    parent[start.F][start.S] = {-1, -1};
    pi end = FAIL;
    s.insert({0, start});

    while (!s.empty()) {
        auto x = *s.begin(); s.erase(s.begin());
        int dist = x.F;
        pi point = x.S;
        if (monsters[point.F][point.S] <= dist) continue;
        if (is_border(point.F, point.S, n, m)) {
            end = point;
            break;
        }
        for (pi n : get_neighbors(point.F, point.S, g)) {
            if (parent[n.F][n.S] == UNVISITED) {
                parent[n.F][n.S] = point;
                s.insert({dist+1, n});
            }
        }
    }

    if (end == FAIL) cout << "NO";
    else {
        cout << "YES\n";
        vector<char> path;
        while (end != start) {
            pi prev = parent[end.F][end.S];
            if (prev.F == end.F - 1) path.PB('D');
            else if (prev.F == end.F + 1) path.PB('U');
            else if (prev.S == end.S - 1) path.PB('R');
            else path.PB('L');
            end = prev;
        }
        reverse(ALL(path));
        cout << path.size();
        for (char c : path) cout << c;
    }

    return 0;
}