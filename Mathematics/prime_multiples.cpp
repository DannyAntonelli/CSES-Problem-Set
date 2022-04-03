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
 
    ll n;
    int k;
    cin >> n >> k;
 
    vector<ll> a(k);
    FOR (i, 0, k) cin >> a[i];
 
    const int MAX_MASK = (1 << k);
    ll ans = 0;
 
    FOR (mask, 1, MAX_MASK) {
        __int128_t curr = 1;
        bool flag = false;
 
        FOR (i, 0, 20)
            if (mask & (1 << i)) {
                curr *= a[i];
                if (curr > n) {
                    flag = true;
                    break;
                }
            }
        
        if (flag) continue;
        if (__builtin_popcount(mask) & 1) ans += n / curr;
        else ans -= n / curr;
    }
 
    cout << ans;
 
    return 0;
}