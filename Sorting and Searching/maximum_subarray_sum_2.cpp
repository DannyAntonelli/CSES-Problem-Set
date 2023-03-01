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

    int n, a, b;
    cin >> n >> a >> b;

    vi x(n);
    vector<ll> pre(n + 1);
    FOR (i, 0, n) {
        cin >> x[i];
        pre[i + 1] = pre[i] + x[i];
    }

    ll ans = pre[a];
    multiset<ll> prefixes;
    FOR (i, a, n + 1) {
        prefixes.insert(pre[i - a]);
        ans = max(ans, pre[i] - *prefixes.begin());
        if (i >= b) prefixes.erase(prefixes.find(pre[i - b]));
    }

    cout << ans;

    return 0;
}
