#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<vector<bool>> imp(8, vector<bool>(8, 0));
vector<vector<bool>> occupied(8, vector<bool>(8, 0));

void solve(int cnt, vector<vector<bool>>) {
    if (cnt == 8) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << (occupied[i][j] ? "Q" : ".");
            }
            cout << endl;
        }
        exit(0);
    }
    vector<vector<bool>> tmp = imp;
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (imp[r][c]) continue;
            occupied[r][c] = 1;
            for (int i = 0; i < 8; ++i) {
                imp[r][i] = 1;
                imp[i][c] = 1;
                if (r + i < 8 && c + i < 8) imp[r + i][c + i] = 1;
                if (r - i >= 0 && c - i >= 0) imp[r - i][c - i] = 1;
                if (r + i < 8 && c - i >= 0) imp[r + i][c - i] = 1;
                if (r - i >= 0 && c + i < 8) imp[r - i][c + i] = 1;
            }
            solve(cnt + 1, imp);
            imp = tmp;
            occupied[r][c] = 0;
        }
    }
}

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_13_A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin >> k;
    vector<pii> queens(k);
    // i->row, j->column
    for (int t = 0; t < k; t++) {
        int r, c;
        cin >> r >> c;
        queens[t] = {r, c};
        occupied[r][c] = 1;
        for (int i = 0; i < 8; ++i) {
            imp[r][i] = 1;
            imp[i][c] = 1;
            if (r + i < 8 && c + i < 8) imp[r + i][c + i] = 1;
            if (r - i >= 0 && c - i >= 0) imp[r - i][c - i] = 1;
            if (r + i < 8 && c - i >= 0) imp[r + i][c - i] = 1;
            if (r - i >= 0 && c + i < 8) imp[r - i][c + i] = 1;
        } 
    }
    solve(k, imp);
}