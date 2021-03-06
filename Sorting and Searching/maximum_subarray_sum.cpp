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

    vector<ll> x(n);
    FOR (i, 0, n) cin >> x[i];

    ll res = 0, curr = 0;
    ll m = *max_element(ALL(x));
    bool flag = false;

    FOR (i, 0, n) {
        if (x[i] >= 0) flag = true;
        if (curr + x[i] > 0) curr += x[i];
        else curr = 0;
        res = max(res, curr);
    }
    
    cout << (flag ? res : m);
        
    return 0;
}