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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }

template<class T>
struct Point {
	typedef Point P;
	T x, y;

	Point(T x=0, T y=0) : x(x), y(y) {}

	P operator-(const P& p) const {
        return P(x - p.x, y - p.y);
    }
	
    T cross(const P& p) const {
        return x * p.y - y * p.x;
    }
	
    T cross(const P& a, const P& b) const {
        return (a - *this).cross(b - *this);
    }
    
    friend istream& operator>>(istream& is, P& p) {
        return is >> p.x >> p.y;
    }
};

int main() {
    fast_io();

    int t;
    cin >> t;

    while (t--) {
        Point<ll> a, b, c, d;
        cin >> a >> b >> c >> d;

        if ((b - a).cross(d - c) == 0) {
            if (a.cross(b, c) != 0)
                cout << "NO\n";
            else
                cout << ((
                    max(a.x, b.x) < min(c.x, d.x) ||
                    max(a.y, b.y) < min(c.y, d.y) ||
                    min(a.x, b.x) > max(c.x, d.x) ||
                    min(a.y, b.y) > max(c.y, d.y)
                ) ? "NO" : "YES") << '\n';
            continue;
        }

        int x = sgn(a.cross(b, c)) * sgn(a.cross(b, d));
        int y = sgn(c.cross(d, a)) * sgn(c.cross(d, b));

        cout << (x <= 0 && y <= 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
