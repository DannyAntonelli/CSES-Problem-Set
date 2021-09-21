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
 
const int MOD = 1e9 + 7;
map<ll, ll> memo;
 
ll fibo(ll n) {
    if (memo.count(n)) return memo[n];

    if (n & 1) {
        ll m = (n + 1) / 2;
        memo[n] = ((fibo(m) * fibo(m)) % MOD + (fibo(m - 1) * fibo(m - 1)) % MOD) % MOD ;
        return memo[n];
    }
    else {
        ll m = n / 2;
        memo[n] = (fibo(m) * ((2 * fibo(m + 1) - fibo(m) + MOD) % MOD)) % MOD;
        return memo[n];
    }
 
}
 
int main() {
    fast_io();

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    ll n;
    cin >> n;
    cout << fibo(n);
    
    return 0;
}