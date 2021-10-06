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

    vi w(n);
    FOR (i, 0, n) cin >> w[i];

    vector<pi> dp(1 << n, {n, 0});
    dp[0] = {0, x};

    FOR (mask, 1, 1 << n) {
        FOR (i, 0, n) {
            if (mask & (1 << i)) {
                pi p = dp[mask ^ (1 << i)];
                if (p.S + w[i] <= x) {
                    p.S += w[i];
                }
                else {
                    ++p.F;
                    p.S = w[i];
                }
                dp[mask] = min(dp[mask], p);
            }
        }
    }

    cout << dp.back().F;

    return 0;
}