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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    FOR (i, 0, n) {
        string s;
        cin >> s;
        nums[i] = stoi(s, 0, 2);
    }

    int ans = k;
    FOR (i, 0, n)
        FOR (j, i + 1, n)
            ans = min(ans, __builtin_popcount(nums[i] ^ nums[j]));

    cout << ans;

    return 0;
}
