#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ld long double

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, X;
    cin >> N >> X;
    vector<int> S(N), C(N);
    vector<ld> P(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i] >> P[i];
        P[i] /= 100.0L;
    }

    int M = 1 << N;
    vector<vector<ld>> dp(X + 1, vector<ld>(M, 0.0L));

    for (int nowCost = 1; nowCost <= X; nowCost++) {
        for (int mask = 0; mask < M; mask++) {
            dp[nowCost][mask] = dp[nowCost - 1][mask];

            for (int i = 0; i < N; i++) {
                if (!(mask & (1 << i)) && nowCost >= C[i]) {
                    int nxt = mask | (1 << i);
                    ld succ = S[i] + dp[nowCost - C[i]][nxt];
                    ld fail = dp[nowCost - C[i]][mask];
                    ld expv = P[i] * succ + (1.0L - P[i]) * fail;
                    dp[nowCost][mask] = max(dp[nowCost][mask], expv);
                }
            }
        }
    }

    cout << fixed << setprecision(10) << dp[X][0] << "\n";
    return 0;
}
