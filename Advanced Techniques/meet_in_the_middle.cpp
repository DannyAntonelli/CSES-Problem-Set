#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
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

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
template<typename Value>
using hashmap = __gnu_pbds::gp_hash_table<ll, Value, chash>;
 
void find_sums(vi& nums, int x, hashmap<ll>& sums) {
    int n = nums.size();
    int MAX_MASK = (1 << n);

    FOR (i, 0, MAX_MASK) {
        int sum = 0;
        FOR (j, 0, n) {
            if (sum > x) break;
            if (i & (1 << j)) sum += nums[j];
        }
        ++sums[sum];
    }
}
 
int main() {
    fast_io();
 
    int n, x;
    cin >> n >> x;

    int a = (n + 1) / 2, b = n / 2;
    vi left((n + 1) / 2), right(n / 2);
    FOR (i, 0, a) cin >> left[i];
    FOR (i, 0, b) cin >> right[i];
 
    hashmap<ll> sums_left, sums_right;
    find_sums(left, x, sums_left);
    find_sums(right, x, sums_right);
 
    ll res = 0;
 
    for (pi elem : sums_left)
        res += elem.S * sums_right[x - elem.F];
    
    cout << res;
    return 0;
}