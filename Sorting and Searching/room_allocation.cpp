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

struct comp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

int main() {
    fast_io();

    int n;
    cin >> n;
    vector<vi> x;

    FOR (i, 0, n) {
        int a, b;
        cin >> a >> b;
        x.PB({a, b, i});
    }
    sort(ALL(x));

    set<int> free;
    set<vi> cust;
    vi rooms(n);
    int k = 0;

    FOR (i, 1, n + 1) free.insert(i); 

    FOR (i, 0, n) {
        while (!cust.empty()) {
            vi first = *(cust.begin());
            if (first[0] < x[i][0]) {
                free.insert(first[1]);
                cust.erase(cust.begin());
            }
            else break;
        }
        int room = *(free.begin());
        free.erase(free.begin());
        rooms[x[i][2]] = room;
        k = max(k, room);
        cust.insert({x[i][1], room});
    }

    cout << k << "\n";
    for (int room : rooms) 
        cout << room << " ";

    return 0;
}