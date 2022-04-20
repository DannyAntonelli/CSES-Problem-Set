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

const int MOD = 1e9 + 7;
bool grid[1001][1001];
int dp[1001][1001];

int main() {
    fast_io();

    int n;
    cin >> n;
    char c;
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            cin >> c;
            grid[i][j] = c == '.';
        }
    }

    if (!grid[0][0] || !grid[n-1][n-1]) {
        cout << 0;
        return 0;
    }

    FOR (i, 0, n) {
        FOR (j, 0, n) {
            if (grid[i][j]) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if (i == 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }

    cout << dp[n-1][n-1];
    return 0;
}