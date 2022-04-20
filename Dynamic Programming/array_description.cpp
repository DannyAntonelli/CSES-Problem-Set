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

int dp[100000][101];

int main() {
    fast_io();

    const int MOD = 1e9 + 7;

    int n, m; 
    cin >> n >> m;
    vi x(n);
    FOR (i, 0, n) cin >> x[i];
    
    if (x[0]) {
        dp[0][x[0]] = 1;
    }
    else {
        FOR (i, 1, m+1) dp[0][i] = 1;
    }
    
    FOR (i, 1, n) {
        if (x[i]) {
            dp[i][x[i]] += dp[i-1][x[i]];
            dp[i][x[i]] %= MOD;
            if (x[i] - 1 > 0) {
                dp[i][x[i]] += dp[i-1][x[i]-1];
                dp[i][x[i]] %= MOD;
            }
            if (x[i] + 1 <= m) {
                dp[i][x[i]] += dp[i-1][x[i]+1];
                dp[i][x[i]] %= MOD;
            }
        }
        else {
            FOR (j, 1, m+1) {
                if (dp[i-1][j]) {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= MOD;

                    if (j - 1 > 0) {
                        dp[i][j-1] += dp[i-1][j];
                        dp[i][j-1] %= MOD;
                    }
                    if (j + 1 <= m) {
                        dp[i][j+1] += dp[i-1][j];
                        dp[i][j+1] %= MOD;
                    }
                }
            }
        }
    }

    int res = 0;
    FOR (i, 0, m+1) res = (res + dp[n-1][i]) % MOD;

    cout << res;
    return 0;
}