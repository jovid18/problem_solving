#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w;
    cin >> w >> h;
    vector<vector<int>> g(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<bool>> vis(h, vector<bool>(w));
    auto isIn = [&](int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; };
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int ans = 0, cnt = 0;
    function<void(int, int)> dfs = [&](int x, int y) {
        if (!isIn(x, y) || vis[x][y] || !g[x][y]) return;
        vis[x][y] = true;
        cnt++;
        ans = max(ans, cnt);
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isIn(nx, ny) && !vis[nx][ny] && g[nx][ny]) {
                dfs(nx, ny);
            }
        }
        vis[x][y] = false;
        cnt--;
    };
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!vis[i][j] && g[i][j]) {
                cnt = 0;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}