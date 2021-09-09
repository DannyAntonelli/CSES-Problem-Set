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


// Sparse Table data structure
class SparseTable {
    bool idempotent;
    long long (*func)(long long, long long);
    vector<int> log2;
    vector<vector<long long>> table;

public:

    /**
     * Initializes a Sparse Table from a vector<long long>
     * Time Complexity: O(N * log(N))
     * Space Complexity: O(1)
     */
    SparseTable(vector<long long> vec, long long (*func)(long long, long long), bool idempotent=false) {
        int n = vec.size();
        this->idempotent = idempotent;
        this->func = func;

        log2.resize(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            log2[i] = log2[i/2] + 1;
        }

        table.resize(n);
        for (int i = 0; i < n; ++i) {
            table[i].resize(log2[n] + 1);
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; i + (1 << j) <= n; ++j) {
                if (j == 0) {
                    table[i][j] = vec[i];
                }
                else {
                    table[i][j] = func(table[i][j-1], table[i+(1<<(j-1))][j-1]);
                }
            }
        }
    }

    /**
     * Computes the sum of the elements with index in the range [left, right]
     * Time Complexity: O(1) if idempotent, otherwise O(log(N))
     * Space Complexity: O(1)
     */
    long long query(int left, int right) {
        if (idempotent) {
            int x = log2[right - left + 1];
            return func(table[left][x], table[right-(1<<x)+1][x]);
        }
        else {
            int x = log2[right - left + 1];
            long long result = table[left][x];
            left += 1 << x;
            while (left <= right) {
                int x = log2[right - left + 1];
                result = func(result, table[left][x]);
                left += 1 << x;
            }
            return result;
        }
    }
};

ll f(ll a, ll b) {
    return a ^ b;
}

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    FOR (i, 0, n) cin >> a[i];

    SparseTable st{a, f};

    FOR (i, 0, q) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l-1, r-1) << "\n";
    }
    
    return 0;
}