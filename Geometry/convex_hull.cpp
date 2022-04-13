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

vector<Point<ll>> convex_hull(vector<Point<ll>> points, bool collinear_edges=false) {
    vector<Point<ll>> hull;
    sort(ALL(points),
        [](const Point<ll>& a, const Point<ll>& b){ return tie(a.x, a.y) < tie(b.x, b.y); }
    );

    for (int _ = 0; _ < 2; ++_) {
        int sz = hull.size();

        for (Point<ll>& p : points) {
            if ((int) hull.size() && hull.end()[-1] == p) continue;

            while ((int) hull.size() - sz >= 2) {
                auto x = hull.end()[-2].cross(hull.end()[-1], p);
                if (x < 0 || (collinear_edges && x == 0)) break;
                hull.pop_back();
            }

            hull.push_back(p);
        }

        if ((int) hull.size() == 1) return hull;
        hull.pop_back();
        reverse(ALL(points));
    }

    return hull;
}

int main() {
    fast_io();

    int n;
    cin >> n;

    vector<Point<ll>> points(n);
    FOR (i, 0, n) cin >> points[i];

    vector<Point<ll>> hull = convex_hull(points, true);

    cout << hull.size() << "\n";
    for (Point<ll>& p : hull)
        cout << p.x << " " << p.y << "\n";

    return 0;
}
