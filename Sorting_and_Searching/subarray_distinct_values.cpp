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

    int n, k;
    cin >> n >> k;

    vi x(n);
    FOR (i, 0, n) cin >> x[i];

    int l = 0, r = 0;
    map<int, int> occ;
    ll ans = 0;

    for (; r < n; ++r) {
        ++occ[x[r]];

        for (; l < r && (int)occ.size() > k; ++l) {
            ans += r - l;
            --occ[x[l]];

            if (occ[x[l]] == 0) {
                occ.erase(x[l]);
            }
        }
    }

    for (; l < r; ++l) {
        ans += r - l;
        --occ[x[l]];
    }

    cout << ans;

    return 0;
}