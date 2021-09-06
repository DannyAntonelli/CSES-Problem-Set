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

// Fenwick Tree data structure
class FenwickTree {
    int sz;
    vector<long long> tree;

    // Returns the least significant bit of 'x'
    // Time complexity: O(1)
    // Space complexity: O(1)
    int lsb(int x) {
        return x & (-x);
    }
    
public:
    // Initializes an empty Fenwick tree of size 'sz'
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    FenwickTree(int sz) {
        this->sz = sz;
        tree.resize(sz);
    }

    // Initializes a Fenwick Tree from a vector<long long>
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    FenwickTree(vector<long long> vec) {
        sz = (int)vec.size() + 1;
        tree.resize(sz, 0);

        for (int i = 1; i < sz; ++i) {
            tree[i] += vec[i-1];
            int j = i + lsb(i);
            if (j < sz) {
                tree[j] += tree[i];
            }
        }
    }

    // Computes the sum of the elements with index in the range [0, i]
    // Time Complexity: O(log(N))
    // Space Complexity: O(1)
    long long prefix_sum(int i) {
        long long result = 0;
        ++i;
        while (i != 0) {
            result += tree[i];
            i -= lsb(i);
        }
        return result;
    }

    // Computes the sum of the elements with index in the range [left, right]
    // Time Complexity: O(log(N))
    // Space Complexity: O(1)
    long long sum(int left, int right) {
        return prefix_sum(right) - prefix_sum(left - 1);
    }

    // Get the value at index 'i'
    // Time Complexity: O(log(N))
    // Space Complexity: O(1)
    long long get(int i) {
        return sum(i, i);
    }

    // Add the value 'x' to the 'i'-th element
    // Time Complexity: O(log(N))
    // Space Complexity: O(1)
    void add(int i, long long x) {
        ++i;
        while (i < sz) {
            tree[i] += x;
            i += lsb(i);
        }
    }

    // Set the 'i'-th element to 'x'
    // Time Complexity: O(log(N))
    // Space Complexity: O(1)
    void set(int i, long long x) {
        add(i, x - get(i));
    }
};

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;
    vector<ll> x(n);
    FOR (i, 0, n) cin >> x[i];

    FenwickTree tree = FenwickTree(x);
    FOR (i, 0, q) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            tree.set(b-1, c);
        }
        else {
            cout << tree.sum(b-1, c-1) << "\n";
        }
    }
    
    return 0;
}