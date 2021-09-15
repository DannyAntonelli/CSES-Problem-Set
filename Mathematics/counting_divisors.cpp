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

    int n;
    cin >> n;

    const int DIM = 1e6 + 1;
    vi spf(DIM);
    FOR (i, 0, DIM) spf[i] = i;

    for (int i = 2; i * i < DIM; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < DIM; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    while (n--) {
        int x;
        cin >> x;

        map<int, int> factors;
        while (x > 1) {
            ++factors[spf[x]];
            x /= spf[x];
        }

        ll res = 1;
        for (pi p : factors) {
            res *= (p.S + 1);
        }
        cout << res << "\n";
    }
    
    return 0;
}