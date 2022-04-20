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

    int x, n;
    cin >> x >> n;

    multiset<int> lengths;
    lengths.insert(x);
    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    FOR (i, 0, n) {
        int p;
        cin >> p;
        lights.insert(p);

        int l = p;
        auto it_l = lights.lower_bound(p);
        if (it_l != lights.begin()) {
            l = *(--it_l);
        }

        int r = x;
        auto it_r = lights.upper_bound(p);
        if (it_r != lights.end()) {
            r = *(it_r);
        }

        lengths.erase(lengths.lower_bound(r - l));
        lengths.insert(p - l);
        lengths.insert(r - p);

        cout << *(--lengths.end()) << " ";
    }

    return 0;
}