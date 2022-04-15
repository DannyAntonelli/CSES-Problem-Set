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

    P operator+(const P& p) const {
        return P(x + p.x, y + p.y);
    }

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

    T dist2() const {
        return x * x + y * y;
    }

    T dist2(const P& p) const {
        return (*this - p).dist2();
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

    auto cmp_by_x = [](const Point<ll>& a, const Point<ll>& b) {
        return tie(a.x, a.y) < tie(b.x, b.y);
    };
    sort(ALL(points), cmp_by_x);

    auto cmp_by_y = [](const Point<ll>& a, const Point<ll>& b) {
        return tie(a.y, a.x) < tie(b.y, b.x);
    };
    set<Point<ll>, decltype(cmp_by_y)> s(cmp_by_y);
    s.insert(points[0]);
    s.insert(points[1]);

    ll d = points[0].dist2(points[1]);
    int j = 0;

    FOR (i, 2, n) {
        while ((points[i].x - points[j].x) * (points[i].x - points[j].x) >= d)
            s.erase(points[j++]);
        
        auto from = s.upper_bound(points[i] - Point<ll>{0, d});
        auto to = s.lower_bound(points[i] + Point<ll>{0, d});

        for (auto it = from; it != to; ++it)
            d = min(d, points[i].dist2(*it));

        s.insert(points[i]);
    }

    cout << d;

    return 0;
}
