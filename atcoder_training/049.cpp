#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1e18;
int cost[16][16];
int dp[1 << 16][16];

// https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            cost[i][j] = INF;
        }
    }
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        cost[s][t] = d;
    }
    for (int i = 0; i < (1 << v); i++) {
        for (int j = 0; j < v; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    for (int i = 0; i < (1 << v); i++) {
        for (int j = 0; j < v; j++) {
            // i: visited nodes, j: current node
            if (!(i & (1 << j))) continue;
            for (int k = 0; k < v; k++) {
                // k: next node
                if (i & (1 << k)) continue;
                // j -> k
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + cost[j][k]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < v; i++) {
        // i -> 0
        ans = min(ans, dp[(1 << v) - 1][i] + cost[i][0]);
    }
    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}