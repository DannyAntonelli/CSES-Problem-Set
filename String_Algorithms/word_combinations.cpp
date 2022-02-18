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

struct Trie {
    
    struct Node {
        bool marker = false;
        int next[26];
        Node() { for (int& x : next) x = -1; }
    };

    int toidx(char ch) { return ch - 'a'; }

    vector<Node> v = {Node()};

    void insert(string s) {
        int u = 0;
        for (char ch : s) {
            if (v[u].next[toidx(ch)] == -1)
                v[u].next[toidx(ch)] = v.size(), v.emplace_back();
            u = v[u].next[toidx(ch)];
        }
        v[u].marker = true;
    }

    bool find(string s) {
        int u = 0;
        for (char ch : s) {
            if (!move(u, ch)) return false;
        }
        return marker(u);
    }

    int root() { return 0; }

    bool move(int& u, char ch) {
        if (v[u].next[toidx(ch)] == -1) return false;
        u = v[u].next[toidx(ch)];
        return true;
    }

    bool marker(int u) { return v[u].marker; }
};

int main() {
    fast_io();

    const int MOD = 1000000007;

    string word;
    cin >> word;
    int k;
    cin >> k;

    Trie trie{};
    while (k--) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    
    int n = word.size();
    vi dp(n + 1);
    dp[n] = 1;

    RFOR (i, n - 1, -1) {
        auto node = trie.root();
        FOR (j, i, n) {
            if (!trie.move(node, word[j]))
                break;
            if (trie.marker(node))
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
    }

    cout << dp[0];

    return 0;
}