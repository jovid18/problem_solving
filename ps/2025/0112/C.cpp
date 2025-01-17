#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> v;
    vector<vector<bool>> canSet;
    v.resize(n);
    canSet.resize(n);
    for (auto &e : v) {
        e.resize(m);
        for (auto &f : e) {
            cin >> f;
        }
    }
    for (auto &e : canSet) {
        e.resize(m);
    }
    vector<int> row(n);
    vector<int> col(m);
    int x = 0;
    int y = 0;
    row[x]++;
    col[y]++;
    canSet[0][0] = 1;
    for (auto e : s) {
        if (e == 'R') {
            y++;
        } else {
            x++;
        }
        row[x]++;
        col[y]++;
        canSet[x][y] = 1;
    }
    while (true) {
        int rowCnt = 0;
        int colCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (row[i] > 0) {
                rowCnt++;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (col[i] > 0) {
                colCnt++;
            }
        }
        if (rowCnt == 0 && colCnt == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            if (row[i] == 1) {
                int sum = 0;
                int idx = 0;
                for (int j = 0; j < m; ++j) {
                    sum += v[i][j];
                    if (canSet[i][j]) {
                        idx = j;
                    }
                }
                v[i][idx] = -sum;
                canSet[i][idx] = 0;
                row[i]--;
                col[idx]--;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (col[i] == 1) {
                int sum = 0;
                int idx = 0;
                for (int j = 0; j < n; ++j) {
                    sum += v[j][i];
                    if (canSet[j][i]) {
                        idx = j;
                    }
                }
                v[idx][i] = -sum;
                canSet[idx][i] = 0;
                row[idx]--;
                col[i]--;
            }
        }
    }
    for (auto e : v) {
        for (auto f : e) {
            cout << f << " ";
        }
        cout << "\n";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}