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

    set<int> days;
    vector<vi> v(n, vi(3));

    FOR (i, 0, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        ++v[i][1];
        days.insert(v[i][0]);
        days.insert(v[i][1]);
    }

    map<int, int> compressed;
    int tot = 0;

    for (int day : days) {
        compressed[day] = tot++;
    }

    vector<vector<pi>> adj(tot);

    for (vi e : v) {
        adj[compressed[e[0]]].PB({compressed[e[1]], e[2]});
    }

    vector<ll> dp(tot, 0);

    FOR (i, 0, tot) {
        if (i < tot - 1) 
            dp[i + 1] = max(dp[i + 1], dp[i]);
        for (pi p : adj[i]) 
            dp[p.F] = max(dp[p.F], dp[i] + p.S);
    }

    cout << dp[tot - 1];

    return 0;
}