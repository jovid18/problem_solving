#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;
// first -> distance, second -> time
pii path[16][16];
// DP[mask][pos] = {distance, count}
pii DP[1 << 16][16];

// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // initialization
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            path[i][j] = {INF, -INF};
        }
    }
    for (int i = 0; i < (1 << 16); i++) {
        for (int j = 0; j < 16; j++) {
            DP[i][j] = {INF, 0};
        }
    }
    // input
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, d, t, k;
        cin >> s >> d >> t >> k;
        s--, d--;
        path[s][d] = {t, k};
        path[d][s] = {t, k};
    }
    DP[1][0] = {0, 1};
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int now = 0; now < N; ++now) {
            if (!(mask & (1 << now))) continue;
            for (int next = 0; next < N; ++next) {
                if (mask & (1 << next)) continue;
                auto [now_dist, now_count] = DP[mask][now];
                // now -> next
                auto [dist, time] = path[now][next];
                if (now_dist + dist > time) continue;
                int next_dist = now_dist + dist;
                if (DP[mask | (1 << next)][next].first > next_dist) {
                    DP[mask | (1 << next)][next].first = next_dist;
                    DP[mask | (1 << next)][next].second = now_count;
                } else if (DP[mask | (1 << next)][next].first == next_dist) {
                    DP[mask | (1 << next)][next].second += now_count;
                }
            }
        }
    }
    int ans_dist = INF, ans_count = 0;
    for (int i = 1; i < N; ++i) {
        auto [now_dist, now_count] = DP[(1 << N) - 1][i];
        auto [dist, time] = path[i][0];
        if (now_dist + dist > time) continue;
        int next_dist = now_dist + dist;
        if (ans_dist > next_dist) {
            ans_dist = next_dist;
            ans_count = now_count;
        } else if (ans_dist == next_dist) {
            ans_count += now_count;
        }
    }
    if (ans_dist == INF) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << ans_dist << ' ' << ans_count << '\n';
    }
}