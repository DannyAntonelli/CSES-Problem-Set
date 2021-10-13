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

ll ipow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
    }
    return result;
}

ll mod_inverse(ll x) {
    return ipow(x, MOD - 2);
}

int DIM = 1e6 + 1;
vector<ll> fact(DIM, 1), invfact(DIM, 1);

ll binomial_coefficient(ll a, ll b) {
    ll x = (fact[a] * invfact[b]) % MOD;
    ll y = (x * invfact[a - b]) % MOD;
    return y;
}

ll catalan_number(ll n) {
    return (mod_inverse(n + 1) * binomial_coefficient(2 * n, n)) % MOD;
}

int main() {
    fast_io();

    FOR (i, 2, DIM) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = mod_inverse(fact[i]);
    }

    int n;
    cin >> n;

    if (n & 1) cout << "0\n";
    else cout << catalan_number(n / 2) << "\n";
    
    return 0;
}