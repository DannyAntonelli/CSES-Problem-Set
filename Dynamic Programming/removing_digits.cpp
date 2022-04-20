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

int dp[1000001] = {};

int main() {
    fast_io();

    int n;
    cin >> n;

    int digits[6] = {};
    int j, x, curr;

    FOR (i, 1, n+1) {
        j = 0;
        x = i;
        while (x) {
            digits[j++] = x % 10;
            x /= 10;
        }

        curr = 1e9;
        FOR (k, 0, j) {
            int x = i - digits[k];
            if (digits[k] != 0) curr = min(curr, 1 + dp[x]);
        }
        dp[i] = curr;
    }

    cout << dp[n];    
    return 0;
}