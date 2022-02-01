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

    int n, x;
    cin >> n >> x;

    vi h(n), s(n), k(n);
    FOR (i, 0, n) cin >> h[i];
    FOR (i, 0, n) cin >> s[i];
    FOR (i, 0, n) cin >> k[i];

    vector<pi> books;
    
    FOR (i, 0, n) {
        for (int j = 0; (1 << j) < k[i]; ++j) {
            int num = (1 << j);
            books.PB({h[i] * num, s[i] * num});
            k[i] -= num;
        }

        if (k[i]) {
            books.PB({h[i] * k[i], s[i] * k[i]});
        }
    }

    n = (int) books.size();
    vector<vi> dp(n + 1, vi(x + 1, 0));

    FOR (i, 1, n + 1) {
        FOR (j, 0, x + 1) {
            dp[i][j] = dp[i - 1][j];
            if (books[i - 1].F > j) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - books[i - 1].F] + books[i - 1].S);
        }
    }

    cout << *max_element(ALL(dp[n]));

    return 0;
}