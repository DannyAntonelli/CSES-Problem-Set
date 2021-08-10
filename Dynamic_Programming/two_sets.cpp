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
    if (n % 4 != 0 && (n + 1) % 4 != 0) {
        cout << 0;
        return 0;
    }

    const int MOD = 1e9 + 7;
    int target = n * (n + 1) / 4;
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    
    FOR (i, 1, n) {
        vector<ll> temp = dp;
        FOR (j, 0, target - i + 1) {
            if (dp[j])
                temp[i+j] = (dp[i+j] + dp[j]) % MOD;
        }
        dp = temp;
    }

    cout << dp[target];
    return 0;
}