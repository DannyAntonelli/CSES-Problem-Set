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

void solve() {
    int n;
    cin >> n;

    bool win = false;
    FOR (i, 0, n) {
        int x;
        cin >> x;
        win = win || (x & 1);
    }

    cout << (win ? "first" : "second") << "\n";
}

int main() {
    fast_io();

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
