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

vector<ll> dp_old, dp_cur, pre;

inline ll cost(int i, int j) {
    return (pre[j + 1] - pre[i]) * (pre[j + 1] - pre[i]);
}

void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<ll, int> best = {LLONG_MAX, -1};

    for (int k = optl; k <= min(mid, optr); ++k)
        best = min(best, {(k ? dp_old[k - 1] : 0) + cost(k, mid), k});

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main() {
    fast_io();

    int n, k;
    cin >> n >> k;

    dp_old.resize(n);
    dp_cur.resize(n);
    pre.resize(n + 1);

    FOR (i, 0, n) {
        int x; cin >> x;
        pre[i + 1] = pre[i] + x;
    }

    FOR (i, 0, n)
        dp_old[i] = cost(0, i);

    FOR (i, 1, k) {
        compute(0, n - 1, 0, n - 1);
        dp_old = dp_cur;
    }

    cout << dp_cur[n - 1];

    return 0;
}
