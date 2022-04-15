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

    bool operator==(const P& p) const {
        return tie(x, y) == tie(p.x, p.y);
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

    int n;
    cin >> n;

    vector<Point<ll>> points(n);
    FOR (i, 0, n) cin >> points[i];

    ll double_area = 0;
    FOR (i, 0, n)
        double_area += points[i].cross(points[(i + 1) % n]);
    cout << abs(double_area);

    return 0;
}
