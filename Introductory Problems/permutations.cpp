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

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3";
        return 0;
    }

    int m = n / 2, k = 0, i = m, j = n;
    int v[n] = {};

    FOR (_, 1, m+1) {
        v[k++] = j--;
        v[k++] = i--;
    }

    if (n % 2 == 1) v[k] = m + 1;

    FOR (i, 0, n) {
        cout << v[i] << " ";
    }

    return 0;
}