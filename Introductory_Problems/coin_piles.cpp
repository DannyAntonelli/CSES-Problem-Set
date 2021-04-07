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
    int a, b;
    cin >> a >> b;
    int diff;

    if (a > b) {
        diff = a - b;
        a -= 2 * diff;
        b -= diff;
    }
    else {
        diff = b - a;
        b -= 2 * diff;
        a -= diff;
    }

    if (a < 0 || a % 3) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    fast_io();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}