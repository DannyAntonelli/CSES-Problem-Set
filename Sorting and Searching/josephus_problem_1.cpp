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

    deque<int> circle;
    FOR (i, 1, n + 1) circle.PB(i); 

    for (int i = 0; !circle.empty(); ++i) {
        int first = circle.front();
        circle.pop_front();
        if (i & 1) cout << first << " ";
        else circle.PB(first);
    }

    return 0;
}