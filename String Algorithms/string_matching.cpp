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

vi get_lps(string s) {
    int n = s.length();
    vi lps(n, 0);
    int curr = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[curr])
            lps[i++] = ++curr;
        else if (curr != 0)
            curr = lps[curr - 1];
        else
            ++i;
    }

    return lps;
}

int kmp(string s, string p) {
    int n = s.length(), k = p.length();
    vi lps = get_lps(p);
    int i = 0, j = 0;
    int res = 0;

    while (i < n) {
        if (s[i] == p[j]) {
            ++i; ++j;
        }
        if (j == k) {
            j = lps[j - 1];
            ++res;
        }
        else if (i < n && s[i] != p[j]) {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }
    }

    return res;
}

int main() {
    fast_io();

    string s, p;
    cin >> s >> p;
    cout << kmp(s, p);
    
    return 0;
}