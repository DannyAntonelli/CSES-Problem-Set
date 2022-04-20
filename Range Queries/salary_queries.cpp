#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i > (b); --i)
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> pi;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vi p(n);
    ordered_set<pi> salaries;

    FOR (i, 0, n) {
        cin >> p[i];
        salaries.insert({p[i], i});
    }

    while (q--) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        --a;

        if (t == '!') {
            salaries.erase({p[a], a});
            salaries.insert({b, a});
            p[a] = b;
        }
        else {
            cout << salaries.order_of_key({b, INT_MAX}) - salaries.order_of_key({a, INT_MAX}) << "\n"; 
        }
    }


    return 0;
}