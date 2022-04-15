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

ll sum_first(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    fast_io();

    int n;
    cin >> n;

    vi r(n);
    FOR (i, 0, n) cin >> r[i];

    ld ev = 0.0L;

    FOR (i, 0, n) {
        FOR (j, i + 1, n) {
            ld count = 0;
            if (r[i] <= r[j])
                count = sum_first(r[i] - 1);
            else
                count = sum_first(r[j]) + r[j] * (r[i] - r[j] - 1);
            ev += count / (r[i] * r[j]);
        }
    }

    cout << fixed << setprecision(6) << ev;

    return 0;
}
