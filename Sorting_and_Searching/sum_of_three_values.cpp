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

ll get_products(vector<ll> k, ll x) {
    ll res = 0;
    for (ll num : k) {
        res += x / num;
        if (res < 0) return -1;
    }
    return res;
}

int main() {
    fast_io();

    int n, x;
    cin >> n >> x;
    vector<pi> a(n);
    FOR (i, 0, n) {
        int num;
        cin >> num;
        a[i] = {num, i + 1};
    }
    sort(ALL(a));

    FOR (i, 0, n - 2) {
        int lo = i + 1, hi = n - 1;
        int target = x - a[i].F;
        while (lo < hi) {
            int s = a[lo].F + a[hi].F;
            if (s == target) {
                cout << a[i].S << " " << a[lo].S << " " << a[hi].S;
                return 0;
            }
            else if (s < target) ++lo;
            else --hi;
        }
    }
    
    cout << "IMPOSSIBLE\n";

    return 0;
}