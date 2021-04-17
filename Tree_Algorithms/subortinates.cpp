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

void solve(int i, int n, vector<vi> &s, int children[]) {
    int res = s[i].size();
    for (int j : s[i]) {
        if (children[i] == -1) solve(j, n, s, children);
        res += children[j];
    }
    children[i] = res;
}

int main() {
    fast_io();

    int n;
    cin >> n;
    vector<vi> s(n);
    int x;
    FOR (i, 0, n-1) {
        cin >> x;
        s[x-1].PB(i+1);
    }
    
    int children[n];
    memset(children, -1, sizeof(children));

    FOR (i, 0, n) {
        if (children[i] == -1) solve(i, n, s, children);
    }

    FOR (i, 0, n) cout << children[i] << " ";

    return 0;
}