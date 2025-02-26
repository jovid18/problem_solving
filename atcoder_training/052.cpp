#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;
int dp[1 << 20];
// n: number of toys, m: sorts of toys
int n, m;
vector<int> toy, cnt;
vector<int> presum[20];

int solve(int mask) {
    if (dp[mask] != INF) return dp[mask];
    // filtered_mask: mask without i-th bit
    for (int i = 0; i < m; i++) {
        if (!(mask & (1 << i))) continue;
        int filtered_mask = mask ^ (1 << i);
        int filtered_cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (filtered_mask & (1 << j)) filtered_cnt += cnt[j];
        }
        int cost = presum[i][filtered_cnt + cnt[i]] - presum[i][filtered_cnt];
        dp[mask] = min(dp[mask], solve(filtered_mask) + cost);
    }
    return dp[mask];
}

// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    toy.resize(n);
    cnt.resize(m);
    for (int i = 0; i < (1 << m); i++) dp[i] = INF;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        k--;
        toy[i] = k;
        cnt[k]++;
    }
    for (int i = 0; i < m; i++) {
        presum[i].resize(n + 1);
        for (int j = 0; j < n; j++) {
            presum[i][j + 1] = presum[i][j] + (toy[j] != i);
        }
    }
    dp[0] = 0;
    cout << solve((1 << m) - 1) << '\n';
}