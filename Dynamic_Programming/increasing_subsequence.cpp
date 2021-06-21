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
    vi x(n);
    FOR (i, 0, n) cin >> x[i];

    vi lis;

    FOR (i, 0, n) {
        auto it = lower_bound(ALL(lis), x[i]);
        if (it == lis.end())
            lis.PB(x[i]);
        else
            *it = x[i];
    }

    cout << lis.size();
    return 0;
}