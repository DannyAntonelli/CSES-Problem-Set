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

    int n; cin >> n;
    ll t; cin >> t;
    vector<ll> k(n);
    FOR (i, 0, n) cin >> k[i];

    ll lo = 1, hi = t * k[0];

    while (lo < hi) {
        ll mid = lo / 2 + hi / 2 + ((lo & 1) + (hi & 1)) / 2;
        ll x = get_products(k, mid);

        if (x == -1 || x >= t)
            hi = mid;
        else 
            lo = mid + 1;
    }
    cout << (get_products(k, lo) < t ? lo + 1 : lo);
    
    return 0;
}