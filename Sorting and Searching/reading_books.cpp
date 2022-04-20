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

    int max_time = 0;
    ll total_time = 0;
    FOR (i, 0, n) {
        int t;
        cin >> t;
        max_time = max(max_time, t);
        total_time += t;
    }
    
    ll diff = total_time - max_time;
    if (diff < max_time) cout << total_time + max_time - diff;
    else cout << total_time;

    return 0;
}