#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;
const int MOD = 10007;
int toInt(char c) {
    if (c == 'J') return 1;
    if (c == 'O') return 2;
    if (c == 'I') return 4;
    return 0;
}
// dp[mask][idx]
int dp[8][1001];

// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // initialization
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 1001; j++) {
            dp[i][j] = -INF;
        }
    }
    int n;
    string s;
    cin >> n >> s;
    for (int mask = 0; mask < (1 << 3); ++mask) {
        if (!(mask & toInt(s[0]))) continue;
        if (!(mask & toInt('J'))) continue;
        dp[mask][0] = 1;
    }
    for (int mask = 0; mask < (1 << 3); mask++) {
        if (dp[mask][0] == -INF) continue;
    }
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < (1 << 3); mask++) {
            if (!(mask & toInt(s[i]))) continue;
            for (int prev_mask = 0; prev_mask < (1 << 3); prev_mask++) {
                if (!(prev_mask & toInt(s[i - 1]))) continue;
                if (dp[prev_mask][i - 1] == -INF) continue;
                if (!(mask & prev_mask)) continue;
                dp[mask][i] = dp[mask][i] == -INF ? dp[prev_mask][i - 1] : dp[mask][i] + dp[prev_mask][i - 1];
                dp[mask][i] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << 3); mask++) {
        if (!(mask & toInt(s[n - 1]))) continue;
        if (dp[mask][n - 1] == -INF) continue;
        ans += dp[mask][n - 1];
        ans %= MOD;
    }
    cout << ans << '\n';
}