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

struct PushRelabel {

    struct Edge {
        int dest, back;
        ll f, c;
    };

    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge*> cur;
    vector<vector<int>> hs;
    vector<int> H;

    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}

    void add_edge(int s, int t, ll cap, ll rcap=0) {
        if (s == t) return;
        g[s].push_back({t, (int) g[t].size(), 0, cap});
        g[t].push_back({s, (int) g[s].size() - 1, 0, rcap});
    }

    void add_flow(Edge& e, ll f) {
        Edge& back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f, e.c -= f, ec[e.dest] += f;
        back.f -= f, back.c += f, ec[back.dest] -= f;
    }

    ll calc(int s, int t) {
        int v = (int) g.size();
        H[s] = v;
        ec[t] = 1;

        vector<int> co(2 * v);
        co[0] = v - 1;
        for(int i = 0; i < v; ++i) cur[i] = g[i].data();
        for (Edge& e : g[s]) add_flow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty())
                if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();

            while (ec[u] > 0) {
                if (cur[u] == g[u].data() + (int) g[u].size()) {
                    H[u] = 1e9;

                    for (Edge& e : g[u])
                        if (e.c && H[u] > H[e.dest] + 1)
                            H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for (int i = 0; i < v; ++i)
                            if (hi < H[i] && H[i] < v)
                                --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                }
                else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
            }
        }
    }

    bool left_of_min_cut(int a) {
        return H[a] >= (int) g.size();
    }
};
 
int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    PushRelabel pr{n};
    
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        pr.add_edge(a - 1, b - 1, 1, 1);
    }

    pr.calc(0, n - 1);
    vector<pi> ans;

    FOR (i, 0, n) {
        if (!pr.left_of_min_cut(i)) continue;

        for (auto e : pr.g[i])
            if (!pr.left_of_min_cut(e.dest))
                ans.PB({i + 1, e.dest + 1});
    }

    cout << ans.size() << "\n";

    for (pi e : ans)
        cout << e.F << " " << e.S << "\n";

    return 0;
}
