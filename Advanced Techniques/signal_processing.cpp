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
using C = complex<ld>;

typedef vector<int> vi;
typedef pair<int, int> pi;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void fft(vector<C>& a) {
    int n = (int) a.size();
    int L = 31 - __builtin_clz(n);

    static vector<C> R(2, 1);
    static vector<C> rt(2, 1);

    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);

        for (int i = k; i < 2 * k; ++i)
            rt[i] = R[i] = (i & 1) ? R[i / 2] * x : R[i / 2];
    }

    vi rev(n);
    for (int i = 0; i < n; ++i)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;

    for (int i = 0; i < n; ++i)
        if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; ++j) {
                auto x = (ld *) &rt[j + k];
                auto y = (ld *) &a[i + j + k];
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
        }
}

vector<ld> conv(const vector<ld>& a, const vector<ld>& b) {
    if (a.empty() || b.empty()) return {};

    vector<ld> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz((int) res.size());
    int n = 1 << L;
    vector<C> in(n), out(n);
    copy(ALL(a), begin(in));

    for (int i = 0; i < (int) b.size(); ++i)
        in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;

    for (int i = 0; i < n; ++i)
        out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);

    for (int i = 0; i < (int) res.size(); ++i)
        res[i] = imag(out[i]) / (4 * n);

    return res;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;

    vector<ld> a(n), b(m);
    FOR (i, 0, n) cin >> a[i];
    FOR (i, 0, m) cin >> b[i];
    reverse(ALL(b));

    vector<ld> c = conv(a, b);
    FOR (i, 0, n + m - 1)
        cout << llround(c[i]) << " ";

    return 0;
}
