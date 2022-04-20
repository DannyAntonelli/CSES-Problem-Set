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

void tower_of_hanoi(int n, int i, int j) {
    if (n == 0) return;

    int k;

    if (i == 1) {
        if (j == 2) k = 3;
        else k = 2;
    }
    else if (i == 2) {
        if (j == 1) k = 3;
        else k = 1;
    }
    else {
        if (j == 1) k = 2;
        else k = 1;
    }

    tower_of_hanoi(n-1, i, k);
    cout << i << " " << j << "\n";
    tower_of_hanoi(n-1, k, j);
}

int main() {
    fast_io();

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    tower_of_hanoi(n, 1, 3);

    return 0;
}