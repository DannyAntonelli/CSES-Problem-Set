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
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<pi>> graph(n);
    FOR (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].PB({b-1, c});
    }

    const ll INF = LONG_LONG_MAX;
    vector<ll> distance(n, INF);
    distance[0] = 0;
    
    set<pair<ll, int>> q;
    q.insert({0, 0});

    while (!q.empty()) {
        int i = q.begin()->S;
        q.erase(q.begin());

        for (pi p : graph[i]) {
            int j = p.F, d = p.S;

            if (distance[i] + d < distance[j]) {
                q.erase({distance[j], j});
                distance[j] = distance[i] + d;
                q.insert({distance[j], j});
            }
        }
    }
 
    FOR (i, 0, n) {
        cout << distance[i] << " ";
    }
 
    return 0;
}