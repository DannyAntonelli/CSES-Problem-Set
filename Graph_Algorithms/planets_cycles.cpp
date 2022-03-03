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

void dfs(int u, vector<vi>& adj, vi& ans) {
    for (int v : adj[u]) {
        if (ans[v] != -1) continue;
        ans[v] = 1 + ans[u];
        dfs(v, adj, ans);
    }
}

void floyd(int u, vi& t, vector<vi>& rev, vi& ans) {
    int slow = t[u], fast = t[t[u]];
    
    while (slow != fast) {
        slow = t[slow];
        fast = t[t[fast]];
    }

    slow = u;
    while (slow != fast) {
        slow = t[slow];
        fast = t[fast];
    }

    int len = 1;
    for (fast = t[slow]; slow != fast; ++len)
        fast = t[fast];

    FOR (_, 0, len) {
        ans[slow] = len;
        slow = t[slow];
    }

    FOR (_, 0, len) {
        dfs(slow, rev, ans);
        slow = t[slow];
    }
}

int main() {
    fast_io();

    int n;
    cin >> n;

    vi t(n);
    vector<vi> rev(n);
    FOR (i, 0, n) {
        cin >> t[i], --t[i];
        rev[t[i]].PB(i);
    }

    vi ans(n, -1);
    FOR (i, 0, n)
        if (ans[i] == -1)
            floyd(i, t, rev, ans);

    for (int d : ans)
        cout << d << " ";

    return 0;
}