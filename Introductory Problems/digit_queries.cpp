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

ll ipow(ll base, ll exp, ll mod=0) {
    ll result = 1;
    if (mod) base %= mod;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) {
            result *= base;
            if (mod) result %= mod;
        }
        base *= base;
        if (mod) base %= mod;
    }
    return result;
}

void solve(ll n) {
    int digits = 0;
    ll x = 0, y = 9;

    while (n > x) {
        x += y * (++digits);
        y *= 10;
    }

    x -= (y / 10) * digits;
    n -= x + 1;
    ll z = ipow(10, digits - 1) + n / digits;
    cout << to_string(z)[n % digits] << "\n";
}

int main() {
    fast_io();

    int q;
    cin >> q;
    ll n;

    while (q--) {
        cin >> n;
        solve(n);
    }
    
    return 0;
}