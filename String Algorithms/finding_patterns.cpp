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

struct SuffixArray {
    vector<int> sa, rank, lcp;

    SuffixArray(const string& s) {
        int n = s.size() + 1, cl = 256;
        vector<int> c(n), cn(n), pn(n), cnt(max(n, cl));
        iota(pn.begin(), pn.end(), 0);
        
        sa = rank = c;
        for (int i = 0; i < n-1; i++)
            c[i] = s[i];

        for (int k = 0; k <= n; k = k ? 2 * k : 1) {
            if (k) for (int i = 0; i < n; i++) pn[i] = (sa[i] - k + n) % n;
            for (int i = 0; i < cl; i++) cnt[i] = 0;
            for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
            for (int i = 1; i < cl; i++) cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--) sa[--cnt[c[pn[i]]]] = pn[i];

            cn[sa[0]] = 0; cl = 1;
            for (int i = 1; i < n; i++) {
                if (c[sa[i]] != c[sa[i - 1]] || c[(sa[i] + k) % n] != c[(sa[i - 1] + k) % n])
                    cl++;
                cn[sa[i]] = cl - 1;
            }
            if (cl == n) break;
            c.swap(cn);
        }

        lcp.assign(n - 1, 0);
        for (int i = 0; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, k = 0; i < n-1; i++, k = max(0, k - 1)) {
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            lcp[rank[i] - 1] = k;
        }
    }
};


int main() {
    fast_io();

    string s;
    cin >> s;
    int k;
    cin >> k;

    SuffixArray suffixArray{s};

    while (k--) {
        string p;
        cin >> p;

        int l = 0, r = (int) s.size();
        bool found = false;

        while (l <= r) {
            int mid = (l + r) / 2;
            string sub = s.substr(suffixArray.sa[mid], p.size());

            if (p == sub) {
                found = true;
                break;
            }

            if (p < sub)
                r = mid - 1;
            else
                l = mid + 1;
        }

        if (found) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}