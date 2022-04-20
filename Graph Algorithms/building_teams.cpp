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

int teams[100000] = {};

bool dfs(vector<vi> &graph, int i) {
    priority_queue<pi> q;
    q.emplace(i, 0);
    int a, b;
    teams[i] = 1;

    while (!q.empty()) {
        a = q.top().F;
        b = q.top().S;
        q.pop();

        for (int x : graph[a]) {
            if (!teams[x]) {
                if (b == 2) teams[x] = 1;
                else teams[x] = 2;
                q.emplace(x, teams[x]);
            }
            else if (teams[x] == b) {
                cout << "IMPOSSIBLE";
                return true;
            }
        }
    }
    return false;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vi> graph(n);
    FOR (i, 0, m) {
        cin >> a >> b;
        graph[a-1].PB(b-1);
        graph[b-1].PB(a-1);
    }
    
    FOR (i, 0, n) {
        if (!teams[i] && dfs(graph, i)) {
            return 0;
        }
    }

    FOR (i, 0, n) {
        if (!teams[i]) cout << "1 ";
        else cout << teams[i] << " ";
    }

    return 0;
}