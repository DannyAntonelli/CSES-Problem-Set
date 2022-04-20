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

int min_str_rotation(string s) {
    s += s;
    int n = s.length();
    vector<int> f(n, -1);
    int k = 0;

    for (int i = 1; i < n; ++i) {
        int j = f[i - k - 1];
        while (j != -1 && s[i] != s[k + j + 1]) {
            if (s[i] < s[k + j + 1])
                k = i - j - 1;
            j = f[j];
        }
        if (s[i] != s[k + j + 1]) {
            if (s[i] < s[k])
                k = i;
            f[i - k] = -1;
        }
        else
            f[i - k] = j + 1;
    }

    return k;
}

int main() {
    fast_io();

    string s;
    cin >> s;
    int n = s.length();
    int i = min_str_rotation(s);
    s += s;
    cout << s.substr(i, n);
    
    return 0;
}