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

vi solve(int n) {
    if (n == 0) return vector<int>(1, 0);

    vi res = solve(n - 1);
    
    RFOR (i, res.size() - 1, -1) {
        res.PB(res[i]);
    }

    int x = 1 << (n - 1);
    
    FOR (i, x, res.size()) {
        res[i] ^= x;
    }
        
    return res;
}

int main() {
    fast_io();

    int n;
    cin >> n;

    vi res = solve(n);
    for (int x : res) {
        RFOR (i, n - 1, -1) {
            cout << ((x & (1 << i)) ? 1 : 0);
        }
        cout << "\n";
    }

    return 0;
}