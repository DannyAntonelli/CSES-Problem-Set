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

    int n, x;
    cin >> n >> x;
    int c[n];
    FOR (i, 0, n) cin >> c[i];

    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    FOR (i, 0, n+1) {
        FOR (j, 0, x+1) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    int k;

    FOR (i, 1, n+1) {
        FOR (j, 0, x+1) {
            dp[i][j] = dp[i-1][j];
            k = j - c[i-1];
            if (k >= 0) {
                dp[i][j] = (dp[i][j] + dp[i][k]) % MOD; 
            }
        }
    }
    
    cout << dp[n][x];
    return 0;
}