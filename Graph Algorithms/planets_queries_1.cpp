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

    int n, q;
    cin >> n >> q;

    int m = 30;

    vector<vi> next(n, vi(m));
    FOR (i, 0, n) cin >> next[i][0], --next[i][0];
    
    FOR (j, 1, m) {
        FOR (i, 0, n) {
            int prev = next[i][j - 1];
            next[i][j] = next[prev][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        --x;

        for (int i = 0; i < m; ++i)
            if (k & (1 << i))
                x = next[x][i];
        
        cout << x + 1 << "\n";
    }

    return 0;
}