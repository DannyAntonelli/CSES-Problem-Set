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

    int n, q;
    cin >> n >> q;

    vi x(n);
    FOR (i, 0, n) cin >> x[i];

    vi log2(n+1, 0);
    FOR (i, 2, n+1) log2[i] = log2[i/2] + 1;

    vector<vi> sparse_table(n, vi(log2[n] + 1));
    RFOR (i, n - 1, -1) {
       for (int j = 0; i + (1 << j) <= n; ++j) {
            if (j == 0) {
                sparse_table[i][j] = x[i];
            }
            else {
                sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    FOR (i, 0, q) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int a = log2[r - l + 1];
        cout << min(sparse_table[l][a], sparse_table[r - (1 << a) + 1][a]) << "\n";
    }
    
    return 0;
}