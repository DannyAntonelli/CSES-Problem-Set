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

    string s;
    cin >> s;
    s.push_back('x');

    int res = 0, cur = 1, n = s.length();
    FOR (i, 0, n-1) {
        if (s[i] == s[i+1]) {
            cur += 1;
        }
        else {
            res = max(res, cur);
            cur = 1;
        }
    }
    cout << res;
    return 0;
}