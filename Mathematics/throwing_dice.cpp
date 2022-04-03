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

using Matrix = vector<vector<ll>>;

Matrix mat_mul(const Matrix& a, const Matrix& b, ll mod) {
	assert(a[0].size() == b.size());

	Matrix res(a.size(), vector<ll>(b[0].size(), 0));

	for (int i = 0; i < (int) res.size(); ++i)
		for (int j = 0; j < (int) res[0].size(); ++j)
			for (int k = 0; k < (int) res[0].size(); ++k)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;

	return res;
}

vector<ll> mat_mul(const Matrix& a, const vector<ll>& b, ll mod) {
	assert(a[0].size() == b.size());

	vector<ll> res(a.size(), 0);

	for (int i = 0; i < (int) a.size(); ++i)
		for (int j = 0; j < (int) a[0].size(); ++j)
			res[i] = (res[i] + a[i][j] * b[j]) % mod;

	return res;
}

Matrix mat_pow(const Matrix& b, ll e, ll mod) {
	assert(b[0].size() == b.size());

	Matrix p(b), res(b.size(), vector<ll>(b.size(), 0));

	for (int i = 0; i < (int) b.size(); i++) res[i][i] = 1;
	for (; e; e /= 2) {
		if (e & 1) res = mat_mul(res, p, mod);
		p = mat_mul(p, p, mod);
	}

	return res;
}

ll linear_recurrence(const vector<ll>& a, const vector<ll>& b, const vector<ll>& x, ll n, ll mod) {
	int k = a.size(), h = b.size();
	Matrix m(k + h, vector<ll>(k + h, 0));

	for (int i = 0; i < k - 1; ++i) m[i][i + 1] = 1;
	for (int i = 0; i < k; ++i) m[k - 1][i] = a[k - i - 1];
	for (int i = 0; i < h; ++i) m[k - 1][k + i] = b[i];
	for (int i = 0; i < h; ++i) {
		m[k + i][k] = 1;
		for (int j = 1; j <= i; ++j)
			m[k + i][k + j] = (m[k + i - 1][k + j - 1] + m[k + i - 1][k + j]) % mod;
	}

	vector<ll> xx(k + h, 1);
	for (int i = 0; i < k; ++i) xx[i] = x[i];

	auto res = mat_mul(mat_pow(m, n, mod), xx, mod);
	return (res[0] % mod + mod) % mod;
}

int main() {
    fast_io();

    ll n;
    cin >> n;

    cout << linear_recurrence({1, 1, 1, 1, 1, 1}, {}, {1, 2, 4, 8, 16, 32}, n - 1, 1000000007);

    return 0;
}
