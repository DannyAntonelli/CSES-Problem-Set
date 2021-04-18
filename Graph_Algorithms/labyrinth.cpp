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

bool graph[1001][1001] = {};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char dirs[] = {'U', 'R', 'D', 'L'};
int paths[1001][1001];

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    char c;
    pi start = {0, 0}, end = {0, 0};

    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cin >> c;
            graph[i][j] = c == '.' || c == 'A' || c == 'B';
            if (c == 'A') {
                start = MP(i, j);
            }
            else if (c == 'B') {
                end = MP(i, j);
            }
        }
    }

    graph[start.F][start.S] = false;
    queue<pi> q;
    q.push(start);
    pi a, b;

    while (!q.empty()) {
        a = q.front();
        q.pop();

        FOR (i, 0, 4) {
            b = MP(a.F + dx[i], a.S + dy[i]);

            if (b.F >= 0 && b.F < n && b.S >= 0 && b.S < m && graph[b.F][b.S]) {
                graph[b.F][b.S] = false;
                paths[b.F][b.S] = i;
                q.push(b);
            }
        }
    }

    if (!graph[end.F][end.S]) {
        vi path;

        while (start != end) {
            int i = paths[end.F][end.S];
            path.PB(i);
            end = MP(end.F - dx[i], end.S - dy[i]);
        }

        cout << "YES\n" << path.size() << '\n';
        RFOR (i, path.size()-1, -1) {
            cout << dirs[path[i]];
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}