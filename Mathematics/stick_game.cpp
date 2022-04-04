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

    int n, k;
    cin >> n >> k;

    vi p(k);
    FOR (i, 0, k) cin >> p[i];

    vector<bool> win(n + 1);

    FOR (i, 1, n + 1) {
        for (int x : p) {
            if (i - x >= 0 && win[i - x] == false) {
                win[i] = true;
                break;
            }
        }
        cout << (win[i] ? 'W' : 'L');
    }

    return 0;
}
