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

int parent[100000];
int visited[100000];

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
        parent[i] = -1;
    }

    queue<int> q;
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        a = q.front();
        q.pop();

        for (int c : graph[a]) {
            if (!visited[c]) {
                parent[c] = a;
                visited[c] = true;
                q.push(c);
            }
        }
    }

    if (parent[n-1] == -1) cout << "IMPOSSIBLE";
    else {
        vi path = {n};
        a = n-1;

        while (a != 0) {
            a = parent[a];
            path.PB(a+1);
        }

        cout << path.size() << "\n";
        RFOR (i, path.size()-1, -1) cout << path[i] << " ";
    }
    
    return 0;
}