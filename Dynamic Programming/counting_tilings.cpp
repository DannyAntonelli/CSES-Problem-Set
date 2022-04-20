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

const int MOD = 1e9 + 7;
vector<vi> dp(1001, vi(1 << 11, -1));
int n, m;

void compute_masks(int mask, vi &masks, int j=1, int curr=0) {
    if (j > n) {
        masks.PB(curr);
        return;
    }

    if (mask & (1 << j))
        compute_masks(mask, masks, j + 1, curr);
    else
        compute_masks(mask, masks, j + 1, curr ^ (1 << j));
    
    if (j < n && !(mask & (1 << j)) && !(mask & (1 << (j + 1))))
        compute_masks(mask, masks, j + 2, curr);

}

int solve(int i=0, int mask=0) {
    if (i == m) return mask == 0;
    if (dp[i][mask] != -1) return dp[i][mask];

    dp[i][mask] = 0;
    vector<int> masks;
    compute_masks(mask, masks);

    for (int next_mask : masks)
        dp[i][mask] = (dp[i][mask] + solve(i + 1, next_mask)) % MOD;

    return dp[i][mask];
}

int main() {
    fast_io();

    cin >> n >> m;
    cout << solve();

    return 0;
}