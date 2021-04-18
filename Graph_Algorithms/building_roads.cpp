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

bool visited[100000];

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    vector<vi> graph(n);
    int a, b;
    FOR (i, 0, m) {
        cin >> a >> b;
        graph[a-1].PB(b-1);
        graph[b-1].PB(a-1);
    }

    stack<int> s;
    vi cc;

    FOR (i, 0, n) {
        if (!visited[i]) {
            cc.push_back(i);
            s.push(i);
            while (!s.empty()) {
                a = s.top();
                s.pop();
                visited[a] = true;

                for (int c : graph[a]) {
                    if (!visited[c]) {
                        s.push(c);
                    }
                }
            }
        }
    }
    
    cout << cc.size() - 1 << "\n";
    FOR (i, 1, cc.size()) {
        cout << cc[0] + 1 << " " << cc[i] + 1 << "\n";
    }

    return 0;
}