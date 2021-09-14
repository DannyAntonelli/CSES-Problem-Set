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

    int t;
    cin >> t;

    while (t--) {
        pair<ll, ll> p1, p2, p3;
        cin >> p1.F >> p1.S >> p2.F >> p2.S >> p3.F >> p3.S;
        
        pair<ll, ll> dir1{p2.F - p1.F, p2.S - p1.S};
        pair<ll, ll> dir2{p3.F - p2.F, p3.S - p2.S};

        if (dir1.F * dir2.S == dir1.S * dir2.F)
            cout << "TOUCH\n";
        else if (dir1.F * dir2.S > dir1.S * dir2.F)
            cout << "LEFT\n";
        else
            cout << "RIGHT\n";
    }
    
    return 0;
}