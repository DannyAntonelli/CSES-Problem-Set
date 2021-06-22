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

struct comp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

int main() {
    fast_io();

    int n;
    cin >> n;
    vector<pi> x;

    FOR (i, 0, n) {
        int a, b;
        cin >> a >> b;
        x.PB({a, b});
    }
    sort(ALL(x));

    int res = 0;
    priority_queue<pi, vector<pi>, comp> q;

    for (pi p : x) {
        int a = p.F, b = p.S;
        while (!q.empty()) {
            pi y = q.top();
            if (y.S <= a)
                q.pop();
            else
                break;
        }
        q.push({a, b});
        res = max(res, (int)q.size());
    }

    cout << res;
    return 0;
}