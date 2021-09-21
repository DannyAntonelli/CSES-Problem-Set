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

    vi ans(n, 0);

    FOR (i, 1, n) {
        int prev = i;
        while (prev != 0 && x[prev - 1] >= x[i]) 
            prev = ans[prev - 1];
        ans[i] = prev;
    }

    for (int num : ans) cout << num << " ";

    return 0;
}