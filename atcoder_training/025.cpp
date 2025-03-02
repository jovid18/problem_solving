#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://onlinejudge.u-aizu.ac.jp/problems/1160
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        int w, h;
        cin >> w >> h;
        if (!w && !h) break;
        vector<vector<int>> g(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> g[i][j];
            }
        }
        int cnt = 0;
        vector<vector<bool>> vis(h, vector<bool>(w));
        auto isIn = [&](int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; };
        int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
        function<void(int, int)> dfs = [&](int x, int y) {
            if (!isIn(x, y) || vis[x][y] || !g[x][y]) return;
            vis[x][y] = true;
            for (int i = 0; i < 8; ++i) {
                dfs(x + dx[i], y + dy[i]);
            }
        };
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!vis[i][j] && g[i][j]) {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        cout << cnt << '\n';
    }
}