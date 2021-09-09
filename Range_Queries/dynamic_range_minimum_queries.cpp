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

// Segment Tree data structure
class SegmentTree {
    int size;
    vector<long long> tree;
    long long (*func)(long long, long long);

public:

    /**
     * Initializes a Segment Tree from a vector<long long>
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    SegmentTree(vector<long long> vec, long long (*func)(long long, long long)) {
        size = vec.size();
        this->func = func;
        tree.resize(2 * size);

        for (int i=0; i < size; i++)
            tree[size+i] = vec[i];

        for (int i = size - 1; i > 0; --i) {
            int x = i << 1;
            tree[i] = func(tree[x], tree[x+1]);
        }
    }

    /**
     * Get the 'i'-th element
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    long long get(int i) {
        return tree[i+size];
    }

    /**
     * Set the 'i'-th element to 'x'
     * Time Complexity: O(log(N))
     * Space Complexity: O(1)
     */
    void set(int i, long long x) {
        tree[i+size] = x;
        i += size;
        
        for (int j = i; j > 1; j >>= 1)
            tree[j>>1] = func(tree[j], tree[j^1]);
    }

    /**
     * Computes the query for the elements with index in the range [left, right]
     * Time Complexity: O(log(N))
     * Space Complexity: O(1)
     */
    long long query(int left, int right) {
        long long result = 0;
        bool flag = false;
     
        for (left += size, right += size + 1; left < right; left >>= 1, right >>= 1) {
            if (left & 1) {
                if (!flag) {
                    result = tree[left++];
                    flag = true;
                }
                else {
                    result = func(result, tree[left++]);
                }
            }
            if (right & 1) {
                if (!flag) {
                    result = tree[--right];
                    flag = true;
                }
                else {
                    result = func(result, tree[--right]);
                }
            }
        }
        
        return result;
    }
};

ll f(ll x, ll y) {
    return min(x, y);
}

int main() {
    fast_io();

    int n, q;
    cin >> n >> q;

    vector<ll> x(n);
    FOR (i, 0, n) cin >> x[i];

    SegmentTree tree{x, f};

    FOR (i, 0, q) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            tree.set(b-1, c);
        }
        else {
            cout << tree.query(b-1, c-1) << "\n";
        }
    }
    
    return 0;
}