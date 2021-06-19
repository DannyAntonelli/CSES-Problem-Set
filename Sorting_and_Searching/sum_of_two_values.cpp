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
    int v[n];
    vi a(n);

    FOR (i, 0, n) {
        cin >> a[i];
        v[i] = a[i];
    }
    sort(ALL(a));

    const int INF = (1 << 20);
    int num1 = INF, num2 = INF;

    for (auto i = a.begin(); i != a.end(); ++i) {
        auto j = lower_bound(i + 1, a.end(), x - *i);

        if (*i + *j == x) {
            num1 = *i;
            num2 = *j;
            break;
        }
    }

    if (num1 == INF) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int idx1 = -1, idx2 = -1;

    FOR (i, 0, n) {
        if (v[i] == num1 && idx1 == -1) {
            idx1 = i + 1;
        }
        if (v[i] == num2 && i != idx1 - 1 && idx2 == -1) {
            idx2 = i + 1;
        }
    }

    if (idx1 == -1 || idx2 == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << idx1 << " " << idx2;
    return 0;
}