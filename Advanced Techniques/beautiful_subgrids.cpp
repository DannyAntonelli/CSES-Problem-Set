#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

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

    constexpr int MAX_N = 3001;
    vector<bitset<MAX_N>> grid(n);

    FOR (i, 0, n) {
        FOR (j, 0, n) {
            char c;
            cin >> c;
            grid[i][j] = (c == '1');
        }
    }

    ll ans = 0;
    FOR (i, 0, n) {
        FOR (j, i + 1, n) {
            ll x = (grid[i] & grid[j]).count();
            ans += x * (x - 1) / 2;
        }
    }

    cout << ans;

    return 0;
}
