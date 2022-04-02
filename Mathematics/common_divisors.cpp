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

    constexpr int MAX_ELEM = 1000001;
    vi occ(MAX_ELEM);
    FOR (i, 0, n) {
        int x;
        cin >> x;
        ++occ[x];
    }

    RFOR (i, MAX_ELEM, -1) {
        int count = 0;
        for (int j = i; j < MAX_ELEM; j += i)
            count += occ[j];
        if (count > 1) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
