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
    int w[n];
    ll res = 0;

    FOR (i, 0, n) {
        cin >> w[i];
        res += w[i];
    }

    ll sum1, sum2;
    FOR (i, 1, 1 << n) {
        sum1 = 0;
        sum2 = 0;
        FOR (j, 0, n) {
            if (i & (1 << j)) {
                sum1 += w[j];
            }
            else {
                sum2 += w[j];
            }
        }
        res = min(res, abs(sum1 - sum2));
    }
    
    cout << res;
    return 0;
}