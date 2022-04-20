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

    int t;
    cin >> t;

    const int MOD = 1e9 + 7;
    const int MAX_N = 1e6;
    vector<vi> dp(MAX_N, vi(2));
    dp[0][0] = dp[0][1] = 1;

    FOR (i, 1, MAX_N) {
        ll a = dp[i - 1][0];
        ll b = dp[i - 1][1];
        ll c = (a + b) % MOD;
        ll d = (2LL * a) % MOD;

        dp[i][0] = (a + c + d) % MOD;
        dp[i][1] = (b + c) % MOD;
    }

    while (t--) {
        int n; cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << "\n";
    }

    return 0;
}