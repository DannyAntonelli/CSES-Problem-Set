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
 
struct MoQuery {
    int x, y, idx; // [x, y]
    static const int block_size = 450; // should be ~sqrt(MAX_N)
    bool operator<(const MoQuery& rhs) const {
        if (x / block_size != rhs.x / block_size)
            return x / block_size < rhs.x / block_size;
        if (x / block_size & 1) return y < rhs.y;
        return y > rhs.y;
    }
};
 
vector<int> mo_algorithm(vector<MoQuery>& queries, vector<int>& x) {
    vi occ(x.size());
    int res = 0;
 
    auto add = [&](int idx) {
        if (occ[x[idx]]++ == 0) ++res;
    };
    auto remove = [&](int idx) {
        if (--occ[x[idx]] == 0) --res;
    };
 
    sort(queries.begin(), queries.end());
    int left = 0, right = -1;
    vector<int> result(queries.size());
 
    for (MoQuery& query : queries) {
        while (left > query.x) left--, add(left);
        while (left < query.x) remove(left), left++;
        while (right > query.y) remove(right), right--;
        while (right < query.y) right++, add(right);
        result[query.idx] = res;
    }
 
    return result;
}
 
int main() {
    fast_io();
 
    int n, q;
    cin >> n >> q;
 
    vi x(n);
    FOR (i, 0, n) cin >> x[i];
 
    vi compressed = x;
    sort(ALL(compressed));
    int sz = 1;
    FOR (i, 1, n)
        if (compressed[i] != compressed[i - 1])
            compressed[sz++] = compressed[i];
    compressed.resize(sz);
 
    FOR (i, 0, n)
        x[i] = lower_bound(ALL(compressed), x[i]) - compressed.begin();
 
    vector<MoQuery> queries(q);
    FOR (i, 0, q) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a - 1, b - 1, i};
    }

    for (int ans : mo_algorithm(queries, x))
        cout << ans << "\n";
 
    return 0;
}
