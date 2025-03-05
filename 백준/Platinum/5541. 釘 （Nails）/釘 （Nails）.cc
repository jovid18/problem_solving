#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int cnt[5001][5001];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        z++;
        cnt[x][y] = max(cnt[x][y], z);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = max({cnt[i][j], cnt[i - 1][j] - 1, cnt[i - 1][j - 1] - 1});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (cnt[i][j] > 0) ans++;
        }
    }
    cout << ans << '\n';
}