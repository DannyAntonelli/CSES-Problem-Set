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

bool check(vi& x, int k, ll target) {
    int n = (int) x.size();
    int subarrays = 1;
    ll curr = 0;

    FOR (i, 0, n) {
        if (x[i] > target) return false;
        if (curr + x[i] <= target) {
            curr += x[i];
        }
        else {
            curr = x[i];
            ++subarrays;
        }
    }

    return subarrays <= k;
}

int main() {
    fast_io();

    int n, k;
    cin >> n >> k;

    vi x(n);
    ll sum = 0;

    FOR (i, 0, n) {
        cin >> x[i];
        sum += x[i];
    }

    ll l = 0, r = sum;
    ll ans = sum;

    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(x, k, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}