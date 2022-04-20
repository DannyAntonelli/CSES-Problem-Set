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

bool different(int a, int b, int c, int d) {
    return a != c && a != d && b != c && b != d;
}

int main() {
    fast_io();

    int n, x; 
    cin >> n >> x;
    vi a(n);
    FOR (i, 0, n) cin >> a[i];

    map<int, vector<vi>> sums;
    FOR (i, 0, n) {
        FOR (j, i + 1, n) {
            int num = a[i] + a[j];
            if (sums.count(x - num)) {
                for (vi v : sums[x - num]) {
                    if (different(i, j, v[0], v[1])) {
                        cout << i + 1 << " " << j + 1 << " " << v[0] + 1 << " " << v[1] + 1;
                        return 0;
                    }
                }
            }
            sums[num].PB({i, j});
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}