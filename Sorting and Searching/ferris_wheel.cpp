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
    int a;
    multiset<int> p;
    FOR (i, 0, n) {
        cin >> a;
        p.insert(a);
    }

    int res = 0, b;
    
    while (!p.empty()) {
        ++res;
        a = *p.begin();
        p.erase(p.begin());
        auto it = p.upper_bound(x - a);
        if (it != p.begin()) {
            p.erase(--it);
        }
    }

    cout << res;
    return 0;
}