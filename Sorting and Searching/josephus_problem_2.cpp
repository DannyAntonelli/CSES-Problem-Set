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
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
 
    ordered_set<int> circle;
    FOR (i, 1, n + 1) circle.insert(i);

    for (int i = 0; !circle.empty(); i = (i + k) % n) {
        n = (int) circle.size();
        auto child = circle.find_by_order((i + k) % n);
        cout << *child << " ";
        circle.erase(child);
    }
 
    return 0;
}