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

    int n, q;
    cin >> n >> q;
    int x[n];
    FOR (i, 0, n) cin >> x[i];

    ll prefix[n];
    ll sum = 0;
    FOR (i, 0, n) {
        sum += x[i];
        prefix[i] = sum;
    }

    int a, b;
    FOR (i, 0, q) {
        cin >> a >> b;
        cout << prefix[b-1] - prefix[a-1] + x[a-1] << "\n";
    }
    
    return 0;
}