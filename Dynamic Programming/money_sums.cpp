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

const int DIM = 100001;
bool dp[DIM] = {1};

int main() {
    fast_io();

    int n;
    cin >> n;
    int res = 0, x, dim = 1;

    FOR (i, 0, n) {
        cin >> x;
        RFOR (i, DIM-1, x-1) {
            if (dp[i-x] && !dp[i]) {
                dp[i] = true;
                ++res;
            }
        }
    }

    cout << res << "\n";
    FOR (i, 1, DIM) {
        if (dp[i]) cout << i << " ";
    }

    return 0;
}