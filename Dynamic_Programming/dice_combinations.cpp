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

    const int MOD = (int) 1e9 + 7;
    int n;
    cin >> n;

    ll dp[6] = {0, 0, 0, 0, 0, 1};
    ll temp, j = 0;
    
    FOR (i, 0, n) {
        temp = 0;
        FOR (k, 0, 6) {
            temp += dp[k];
        }
        dp[j] = temp % MOD; 
        j = (j + 1) % 6;
    }

    if (j == 0) j = 6;
    cout << dp[j-1];
    return 0;
}