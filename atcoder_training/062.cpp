#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 0LL << 60;

// https://atcoder.jp/contests/abc079/tasks/abc079_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(10, vector<int>(10, INF));

    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            cin >> g[i][j];
        }
    }
    for (int k = 0; k <= 9; ++k) {
        for (int i = 0; i <= 9; ++i) {
            if (g[i][k] == INF) continue;
            for (int j = 0; j <= 9; ++j) {
                if (g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h * w; ++i) {
        int a;
        cin >> a;
        if (a == -1) continue;
        if (a == 1) continue;
        ans += g[a][1];
    }
    cout << ans << '\n';
}