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

int backtrack(int board[][8], int row, int cols[], int diag1[], int diag2[]) {
    if (row == 8) return 1;
    
    int h, k, res = 0;
    FOR (col, 0, 8) {
        h = row + col;
        k = 7 - row + col;

        if (!(board[row][col] || cols[col] || diag1[h] || diag2[k])) {
            cols[col] = 1;
            diag1[h] = 1;
            diag2[k] = 1;

            res += backtrack(board, row+1, cols, diag1, diag2);

            cols[col] = 0;
            diag1[h] = 0;
            diag2[k] = 0;
        }
    }
    return res;
}

int main() {
    fast_io();

    int board[8][8];
    char c;

    FOR (i, 0, 8) {
        FOR (j, 0, 8) {
            cin >> c;
            board[i][j] = (c == '*' ? 1 : 0);
        }
    }

    int rows[8] = {};
    int cols[8] = {};
    int diag1[15] = {};
    int diag2[15] = {};
    int res = 0;

    cout << backtrack(board, 0, cols, diag1, diag2);    
    
    return 0;
}