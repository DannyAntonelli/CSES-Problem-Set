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

int get_component_size(int u, vector<vi>& adj, vector<bool>& vis) {
    vis[u] = true;
    int sz = 1;
    for (int v : adj[u])
        if (!vis[v])
            sz += get_component_size(v, adj, vis);
    return sz;
}
 
int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    vector<bool> vis(n);
    constexpr int MAX_N = 100001;
    bitset<MAX_N> ans;
    ans[0] = 1;

    FOR (u, 0, n)
        if (!vis[u])
            ans |= (ans << get_component_size(u, adj, vis));

    FOR (i, 1, n + 1) cout << ans[i];

    return 0;
}
