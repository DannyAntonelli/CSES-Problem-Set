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

int dp[5001][5001];

int main() {
    fast_io();

    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();

    int temp;

    FOR (i, 0, n+1) {
        FOR (j, 0, m+1) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                temp = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                dp[i][j] = 1 + temp;
            }
        }
    }
    
    cout << dp[n][m];
    return 0;
}