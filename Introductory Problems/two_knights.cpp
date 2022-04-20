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

void solve(int n) {
    ll m = n * n;
    ll total_comb = m * (m - 1) / 2;
    ll wrong_comb = 4 * (n - 1) * (n - 2);
    cout << total_comb - wrong_comb << "\n";
}

int main() {
    fast_io();

    int n;
    cin >> n;

    FOR (i, 1, n+1) {
        solve(i);
    }
    
    return 0;
}