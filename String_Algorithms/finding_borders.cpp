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

class StringHash {
    long long mod;
    long long x;
    vector<int> inv_pow;
    vector<int> prefix_hash;

    long long ipow(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
        }
        return result;
    }
 
public:

    StringHash(string s, long long x=131, long long mod=1000000007) {
        this->mod = mod;
        this->x = x;

        int n = s.length();
        inv_pow.resize(n, 0);
        prefix_hash.resize(n + 1, 0);
        long long p = 1;
 
        for (int i = 0; i < n; ++i) {
            inv_pow[i] = ipow(p, mod - 2);
            p = (p * x) % mod;
        }
 
        p = 1;
        for (int i = 0; i < n; ++i) {
            prefix_hash[i + 1] = (prefix_hash[i] + (p * (s[i] - '0' + 1)) % mod) % mod;
            p = (p * x) % mod;
        }
    }

    int get_hash(int l, int r) {
        return ((long long)((prefix_hash[r + 1] - prefix_hash[l] + mod) % mod) * (long long)inv_pow[l]) % mod;
    }
};

int main() {
    fast_io();

    string s;
    cin >> s;
    int n = s.length();
    
    StringHash sh{s};

    FOR (i, 0, n - 1) {
        if (sh.get_hash(0, i) == sh.get_hash(n - i - 1, n - 1)) {
            cout << i + 1 << " ";
        }
    }
}