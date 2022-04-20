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

int dp[501][501];

int main() {
    fast_io();

    int a, b;
    cin >> a >> b;

    const int INF = (1 << 20);
    int temp;

    FOR (i, 1, a+1) {
        FOR (j, 1, b+1) {
            temp = INF;
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                FOR (x, 1, i) {
                    temp = min(temp, dp[x][j] + dp[i-x][j]);
                }
                FOR (x, 1, j) {
                    temp = min(temp, dp[i][x] + dp[i][j-x]);
                }
                dp[i][j] = temp + 1;
            }
        }
    }
    
    cout << dp[a][b];
    return 0;
}