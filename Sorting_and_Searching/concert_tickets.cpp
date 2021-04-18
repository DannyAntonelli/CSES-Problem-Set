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

    int n, m;
    cin >> n >> m;

    int a;
    multiset<int> h;
    FOR (i, 0, n) {
        cin >> a;
        h.insert(a);
    }

    int t[m];
    FOR (i, 0, m) cin >> t[i];
    
    FOR (i, 0, m) {
        auto it = h.upper_bound(t[i]);
        if (it != h.begin()) {
            --it;
            cout << *it << "\n";
            h.erase(it);
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}