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

bool graph[1000][1000] = {};

void visit(int i, int j, int n, int m) {
    graph[i][j] = 0;
    if (i-1 >= 0 && graph[i-1][j]) visit(i-1, j, n, m);
    if (j-1 >= 0 && graph[i][j-1]) visit(i, j-1, n, m);
    if (i+1 < n && graph[i+1][j]) visit(i+1, j, n, m);
    if (j+1 < m && graph[i][j+1]) visit(i, j+1, n, m);
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    char c;
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cin >> c;
            graph[i][j] = c == '.';
        }
    }

    int res = 0;
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            if (graph[i][j]) {
                visit(i, j, n, m);
                ++res;
            }
        }
    }
    
    cout << res;
    return 0;
}