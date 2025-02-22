#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> cnt(n * m + 1, 0);
    vector<vector<pair<int, int>>> colorGroup(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int color;
            cin >> color;
            a[i][j] = color;
            colorGroup[color].push_back({i, j});
        }
    }
    vector<int> cost(n * m + 1, 0);
    for (int c = 1; c <= n * m; c++) {
        if (colorGroup[c].empty()) {
            cost[c] = 0;
            continue;
        }
        cost[c] = 1;
        for (auto &cell : colorGroup[c]) {
            int x = cell.first;
            int y = cell.second;

            if (x + 1 < n && a[x + 1][y] == c) {
                cost[c] = 2;
                break;
            }
            if (y + 1 < m && a[x][y + 1] == c) {
                cost[c] = 2;
                break;
            }
        }
    }
    int ans = 0;
    int max_cost = 0;
    for (int i = 1; i <= n * m; i++) {
        if (colorGroup[i].empty()) continue;
        ans += cost[i];
        max_cost = max(max_cost, cost[i]);
    }
    cout << ans - max_cost << '\n';
}

// https://codeforces.com/contest/2069/problem/B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}