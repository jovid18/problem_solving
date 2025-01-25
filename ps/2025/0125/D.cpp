#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int MAX = (1 << 12);
int sum[MAX];
vector<vector<int> > dp(MAX);
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < (1 << N); ++i) {
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                sum[i] += A[j];
            }
        }
    }
    dp[0].push_back(0);
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            int rest = mask ^ sub;
            if (rest > sub) continue;
            int sumSub = sum[sub];
            for (auto &x : dp[rest]) {
                dp[mask].push_back(x ^ sumSub);
            }
        }
        sort(dp[mask].begin(), dp[mask].end());
        dp[mask].erase(unique(dp[mask].begin(), dp[mask].end()), dp[mask].end());
    }
    cout << dp[(1 << N) - 1].size();
}