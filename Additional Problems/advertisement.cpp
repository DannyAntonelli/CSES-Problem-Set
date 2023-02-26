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

    vi k(n);
    for (int& x : k) cin >> x;

    vi next_lower(n, n), prev_lower(n, -1);

    FOR (i, 1, n) {
        int x = i - 1;
        while (x != -1 && k[x] >= k[i])
            x = prev_lower[x];
        prev_lower[i] = x;
    }

    RFOR (i, n - 2, -1) {
        int x = i + 1;
        while (x != n && k[x] >= k[i])
            x = next_lower[x];
        next_lower[i] = x;
    }

    ll ans = 0;
    FOR (i, 0, n) {
        ll area = (ll) (next_lower[i] - prev_lower[i] - 1) * k[i];
        ans = max(area, ans);
    }

    cout << ans << "\n";

    return 0;
}
