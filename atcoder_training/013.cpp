#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc002/tasks/abc002_4
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int R, C;
    cin >> R >> C;
    // i -> R, j -> C
    vector<vector<bool>> G(R, vector<bool>(C, 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int x;
            cin >> x;
            G[i][j] = x;
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << R); mask++) {
        auto copy = G;
        int cnt = 0;
        for (int i = 0; i < R; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < C; j++) {
                    copy[i][j] = !copy[i][j];
                }
            }
        }
        for (int j = 0; j < C; j++) {
            int cnt1 = 0;
            for (int i = 0; i < R; i++) {
                if (copy[i][j]) {
                    cnt1++;
                }
            }
            cnt += max(cnt1, R - cnt1);
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}