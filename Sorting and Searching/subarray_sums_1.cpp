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

    vi a(n);
    FOR (i, 0, n) cin >> a[i];
    
    int curr = 0, ans = 0;
    deque<int> q;

    FOR (i, 0, n) {
        curr += a[i];
        q.PB(a[i]);
        while (curr > x) {
            curr -= q.front();
            q.pop_front();
        }
        if (curr == x) ++ans;
    }

    cout << ans;

    return 0;
}