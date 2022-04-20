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

    int n, m;
    cin >> n >> m;

    vi nums(n), idxs(n);
    FOR (i, 0, n) {
        cin >> nums[i];
        --nums[i];
        idxs[nums[i]] = i;
    }

    int res = 1;
    FOR (i, 1, n)
        if (idxs[i] < idxs[i - 1]) ++res;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        
        int x = nums[a], y = nums[b];
        if (x > y) swap(x, y);

        if (x > 0 && idxs[x] < idxs[x - 1]) --res;
        if (y < n - 1 && idxs[y + 1] < idxs[y]) --res;
        if (idxs[x + 1] < idxs[x]) --res;
        if (x + 1 != y && idxs[y] < idxs[y - 1]) --res;

        swap(idxs[x], idxs[y]);
        swap(nums[a], nums[b]);

        if (x > 0 && idxs[x] < idxs[x - 1]) ++res;
        if (y < n - 1 && idxs[y + 1] < idxs[y]) ++res;
        if (idxs[x + 1] < idxs[x]) ++res;
        if (x + 1 != y && idxs[y] < idxs[y - 1]) ++res;

        cout << res << "\n";
    }

    return 0;
}