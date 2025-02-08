#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> K(N);
    vector<vector<int>> A(N);
    vector<map<int, ld>> prob(N);
    for (int i = 0; i < N; i++) {
        cin >> K[i];
        A[i].resize(K[i]);
        unordered_map<int, int> cnt;
        for (int j = 0; j < K[i]; j++) {
            cin >> A[i][j];
            cnt[A[i][j]]++;
        }
        // k -> num
        // v -> cnt
        for (auto [k, v] : cnt) {
            prob[i][k] = v / (ld)K[i];
        }
    }
    ld ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ld cur = 0;
            // k -> num
            // v -> prob
            for (auto [k, v] : prob[j]) {
                cur += v * prob[i][k];
            }
            ans = max(ans, cur);
        }
    }
    cout << fixed << setprecision(16) << ans << '\n';
}