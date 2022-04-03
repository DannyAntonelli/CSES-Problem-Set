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

vi mu_up_to_n(int n) {
	vi mu(n), lpf(n);
	for (ll p = 2; p <= n; ++p)
		if (!lpf[p]) {
			lpf[p] = p;
			for (ll k = p * p; k <= n; k += p)
				if (!lpf[k])
					lpf[k] = p;
		}
	mu[1] = 1;
	for (int i = 2; i <= n; ++i)
		if (lpf[i / lpf[i]] == lpf[i]) mu[i] = 0;
		else mu[i] = -1 * mu[i / lpf[i]];
    return mu;
}

int main() {
    fast_io();

    int n;
    cin >> n;

    constexpr int MAX_ELEM = 1000001;
    vi occ(MAX_ELEM);
    FOR (i, 0, n) {
        int x;
        cin >> x;
        ++occ[x];
    }

    vi mu = mu_up_to_n(MAX_ELEM);
    ll ans = 0;

    FOR (i, 1, MAX_ELEM) {
        int count = 0;
        for (int j = i; j < MAX_ELEM; j += i)
            count += occ[j];
        ans += (ll) mu[i] * count * (count - 1) / 2;
    }

    cout << ans;

    return 0;
}
