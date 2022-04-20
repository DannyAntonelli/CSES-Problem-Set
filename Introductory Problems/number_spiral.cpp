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

void solve() {
    ll y, x;
    cin >> y >> x;

    ll res, z;
    
    if (x < y) {
        res = (y & 1) ? y*y : (y-1) * (y-1) + 1;
        z = (y - 1) * 2 + 1;
        if (y & 1) res -= z - x;
        else res += z - x;
    }
    else {
        res = (x & 1) ? x*x : (x-1) * (x-1) + 1;
        if (x & 1) res -= y - 1;
        else res += y - 1;
    }
    cout << res << "\n";
}

int main() {
    fast_io();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}