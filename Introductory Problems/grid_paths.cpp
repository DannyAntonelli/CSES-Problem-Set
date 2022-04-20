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

string s;
bool vis[7][7];

bool prune(int x, int y) {
    bool lfree = x >= 0 && x < 7 && y - 1 >= 0 && y - 1 < 7 && !vis[x][y - 1];
    bool rfree = x >= 0 && x < 7 && y + 1 >= 0 && y + 1 < 7 && !vis[x][y + 1];
    bool ufree = x - 1 >= 0 && x - 1 < 7 && y >= 0 && y < 7 && !vis[x - 1][y];
    bool dfree = x + 1 >= 0 && x + 1 < 7 && y >= 0 && y < 7 && !vis[x + 1][y];
 
    if (lfree && rfree && !ufree && !dfree) return true;
    if (ufree && dfree && !rfree && !lfree) return true;
 
    return false;
}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int backtrack(int x=0, int y=0, int i=0) {
    if (x == 6 && y == 0) {
        if (i == 48) return 1;
        return 0;
    }
    if (i == 48) return 0;
    if (vis[6][0]) return 0;
    if (prune(x, y)) return 0;
    
    if (s[i] == '?') {
        int res = 0;
        FOR (j, 0, 4) {
            int new_x = x + dx[j];
            int new_y = y + dy[j];
            if (new_x >= 0 && new_x < 7 && new_y >= 0 && new_y < 7 && !vis[new_x][new_y]) {
                vis[new_x][new_y] = true;
                res += backtrack(new_x, new_y, i + 1);
                vis[new_x][new_y] = false;
            }
        }
        return res;
	}
 
	if (s[i]=='L') --y;
	else if (s[i]=='R') ++y;
	else if (s[i]=='U') --x;
	else ++x;

    int res = 0;
	if (x >= 0 && x < 7 && y >= 0 && y < 7 && !vis[x][y]) {
        vis[x][y] = true;
        res = backtrack(x, y, i + 1);
        vis[x][y] = false;
    }
    return res;
}

int main() {
    fast_io();

    cin >> s;
    vis[0][0] = true;
    cout << backtrack();
    
    return 0;
}