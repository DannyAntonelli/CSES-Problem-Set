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

    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    FOR (i, 0, n) {
        cin >> a[i];
    }
    int b[m];
    FOR (i, 0, m) {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    int i = 0, j = 0, res = 0;

    while (i < n && j < m) {
        if (b[j] >= a[i] - k && b[j] <= a[i] + k) {
            ++i;
            ++j;
            ++res;
        }
        else if (b[j] < a[i] - k) ++j;
        else ++i;
    }
    
    cout << res;
    return 0;
}