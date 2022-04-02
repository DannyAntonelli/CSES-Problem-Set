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

array<ll, 3> egcd(ll a, ll b) {
	ll x = 1, y = 0;
	ll x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		ll q = a1 / b1;
		tie(x, x1) = make_pair(x1, x - q * x1);
		tie(y, y1) = make_pair(y1, y - q * y1);
		tie(a1, b1) = make_pair(b1, a1 - q * b1);
	}
	return {x, y, a1};
}

ll mod_inverse(ll n, ll mod) {
	auto [x, _, g] = egcd(n, mod);
	if(g != 1) return -1;
	return (x % mod + mod) % mod;
}

vector<ll> factorial;
vector<ll> inv_factorial;

void init_factorials(int n, int mod) {
    factorial.resize(n+1);
    inv_factorial.resize(n+1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = (i * factorial[i - 1]) % mod;
    inv_factorial[n] = mod_inverse(factorial[n], mod);
    for (int i = n - 1; i >= 0; --i)
        inv_factorial[i] = ((i + 1) * inv_factorial[i + 1]) % mod;
}


int main() {
    fast_io();

    string s;
    cin >> s;

    constexpr int MOD = 1000000007;
    init_factorials((int) s.length(), MOD);

    vi occ(CHAR_MAX);
    for (char c : s) ++occ[c];

    ll res = factorial[s.length()];
    for (int x : occ)
        res = (res * inv_factorial[x]) % MOD;

    cout << res;

    return 0;
}
