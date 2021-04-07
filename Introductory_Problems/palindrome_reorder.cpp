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

    unordered_map<char, int> occ;
    for (char c : s) {
        ++occ[c];
    }

    string res = "", temp;
    int n;
    bool flag = false;

    for (auto a : occ) {
        if (a.S & 1) {
            if (flag) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            flag = true;
            temp = "";
            FOR (i, 0, a.S) {
                temp.push_back(a.F);
            }
            res = res.substr(0, res.length()/2) + temp + res.substr(res.length()/2, res.length());
        }
        else {
            temp = "";
            n = a.S / 2;
            FOR (i, 0, n) {
                temp.push_back(a.F);
            }
            res = temp + res + temp;
        }
    }

    cout << res;
    
    return 0;
}