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

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<ld>> dp(n + 1, vector<ld>(b + 1));
    dp[0][0] = 1.0L;
    ld res = 0.0L;

    FOR (i, 1, n + 1) {
        FOR (j, 1, b + 1) {
            FOR (k, 1, min(7, j + 1))
                dp[i][j] += 1.0L / 6.0L * dp[i - 1][j - k];

            if (i == n && j >= a)
                res += dp[i][j];
        }
    }

    cout << fixed << setprecision(6) << res;

    return 0;
}
