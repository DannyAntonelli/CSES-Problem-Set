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

    int n;
    cin >> n;

    vi x(n);
    ll tot = 0;
    FOR (i, 0, n) {
        cin >> x[i];
        tot += x[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    RFOR (i, n - 1, -1) {
        FOR (j, i, n) {
            if (i == j)
                dp[i][j] = x[i];
            else
                dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }

    cout << (tot + dp[0][n - 1]) / 2;

    return 0;
}