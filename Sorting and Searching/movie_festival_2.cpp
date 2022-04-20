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

    int n, k;
    cin >> n >> k;

    vector<pi> movies(n);
    FOR (i, 0, n) 
        cin >> movies[i].second >> movies[i].first;

    sort(ALL(movies));
    multiset<int> end;
    int ans = 0;

    FOR (i, 0, n) {
        auto it = end.upper_bound(movies[i].second);

        if (it == end.begin() && (int) end.size() >= k)
            continue;
        if (it != end.begin())
            end.erase(prev(it));
            
        end.insert(movies[i].first);
        ++ans;
    }

    cout << ans << "\n";

    return 0;
}