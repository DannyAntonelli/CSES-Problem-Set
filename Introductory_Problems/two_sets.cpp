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

    ll sum1 = 0, sum2 = 0;
    vi v1, v2;

    RFOR (i, n, 0) {
        if (sum1 < sum2) {
            sum1 += i;
            v1.PB(i);
        }
        else {
            sum2 += i;
            v2.PB(i);
        }
    }

    if (sum1 == sum2) {
        cout << "YES\n";
        
        cout << v1.size() << "\n";
        FOR (i, 0, v1.size()) {
            cout << v1[i] << " ";
        } cout << "\n";

        cout << v2.size() << "\n";
        FOR (i, 0, v2.size()) {
            cout << v2[i] << " ";
        }
    }
    else cout << "NO";
    
    return 0;
}