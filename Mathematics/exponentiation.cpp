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

ll ipow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    fast_io();

    const int MOD = 1e9 + 7;
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << ipow(a, b, MOD) << "\n";
    }
    
    return 0;
}