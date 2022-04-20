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

    int n;
    cin >> n;
    int nums[n];

    FOR (i, 0, n) {
        cin >> nums[i];
    }

    int cur = nums[0];
    ll res = 0;
    FOR (i, 1, n) {
        cur = max(cur, nums[i]);
        res += cur - nums[i];
    }
    cout << res;

    return 0;
}