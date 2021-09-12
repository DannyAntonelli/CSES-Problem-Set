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


// Fenwick Tree which supports range updates and point queries data structure
class FenwickTreePURQ {
    int mod;
    vector<long long> tree;

    /**
     * Returns the value of the least significant bit of 'x'
     * Time complexity: O(1)
     * Space complexity: O(1)
     */
    int lsb(int x) {
        return x & (-x);
    }

    /**
     * Computes the sum of the elements with index in the range [0, i]
     * Time Complexity: O(log(N))
     * Space Complexity: O(1)
     */
    long long prefix_sum(int i) {
        long long result = 0;
        for (++i; i > 0; i -= lsb(i)) {
            result += tree[i];
            if (mod) result %= mod;
        }
        return result;
    }

    /**
     * Add the value 'x' to the 'i'-th element
     * Time Complexity: O(log(N))
     * Space Complexity: O(1)
     */
    void add(int i, long long x) {
        for (++i; i < tree.size(); i += lsb(i)) {
            tree[i] += x;
            if (mod) tree[i] %= mod;
        }
    }
    
public:

    /**
     * Initializes an empty Fenwick tree of 'size' elements
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    FenwickTreePURQ(int sz, int mod=0) {
        this->mod = mod;
        tree.resize(sz + 1);
    }

    /**
     * Initializes a Fenwick Tree from a vector<long long>
     * Time Complexity: O(N * log(N))
     * Space Complexity: O(1)
     */
    FenwickTreePURQ(vector<long long> &vec, int mod=0) {
        this->mod = mod;
        tree.resize(vec.size() + 1, 0);

        for (int i = 0; i < vec.size(); ++i) {
            add_range(i, i, vec[i]);
        }
    }

    /**
     * Get the value at index 'i'
     * Time Complexity: O(log(N))
     * Space Complexity: O(1)
     */
    long long get(int i) {
        return prefix_sum(i);

        // if (mod) return (prefix_sum(i) - prefix_sum(i - 1) + mod) % mod;
        // else return prefix_sum(i) - prefix_sum(i - 1);
    }

    /**
     * Add the value 'x' to all the elements
     * with indexes in the range [left, right]
     * Time Complexity: O(log(N))
     * Space Complexity: O(1)
     */
    void add_range(int left, int right, long long x) {
        add(left, x);
        add(right + 1, -x);
    }
};

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vector<ll> x(n);
    FOR (i, 0, n) cin >> x[i];

    FenwickTreePURQ tree{x};
    FOR (i, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            tree.add_range(a - 1, b - 1, u);
        }
        else {
            int k;
            cin >> k;
            cout << tree.get(k - 1) << "\n";
        }
    }
       
    return 0;
}