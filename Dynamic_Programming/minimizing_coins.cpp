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
    int nums[n];
    FOR (i, 0, n) cin >> nums[i];
    
    const int INF = 1000001;
    int dp[x+1];
    FOR (i, 0, x+1) dp[i] = INF;
    dp[0] = 0;

    int curr = INF, k;
    FOR (i, 1, x+1) {
        curr = INF;
        FOR (j, 0, n) {
            k = i - nums[j];
            if (k >= 0) {
                curr = min(curr, dp[k]);
            }
        }
        dp[i] = 1 + curr;
    }

    cout << (dp[x] >= INF ? -1 : dp[x]);    
    return 0;
}