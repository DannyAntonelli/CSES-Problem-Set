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
    vi k(n);
    FOR (i, 0, n) cin >> k[i];

    int a = 0, b = 0, res = 0;
    set<int> s;

    while (b < n) {
        if (!s.count(k[b])) {
            s.insert(k[b++]);
            res = max(res, (int)s.size());
        }
        else {
            s.erase(k[a++]);
        }
    }
    
    cout << res;
    return 0;
}