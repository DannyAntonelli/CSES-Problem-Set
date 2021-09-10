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

    vector<vector<bool>> forest(n, vector<bool>(n));
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            char c;
            cin >> c;
            forest[i][j] = c == '*';
        }
    }

    vector<vi> dp(n+1, vi(n+1));

    FOR (i, 1, n+1) {
        FOR (j, 1, n+1) {
            dp[i][j] = forest[i-1][j-1];
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1];
            if (i > 0 && j > 0)
                dp[i][j] -= dp[i-1][j-1];
        }
    }

    FOR (i, 0, q) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1] << "\n";
    }
    
    return 0;
}