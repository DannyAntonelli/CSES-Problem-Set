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

int h[1000], s[1000], dp[1001][100001];

int main() {
    fast_io();

    int n, x;
    cin >> n >> x;
    FOR (i, 0, n) cin >> h[i];
    FOR (i, 0, n) cin >> s[i];

    int curr;

    FOR (i, 1, n+1) {
        FOR (j, 1, x+1) {
            if (h[i-1] <= j) {
                curr = s[i-1] + dp[i-1][j - h[i-1]];
                dp[i][j] = max(curr, dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][x];    
    return 0;
}