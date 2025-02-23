#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int DP[101][101];

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    memset(DP, 0x3f, sizeof(DP));
    for (int k = 0; k < n; ++k) {
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                DP[i][i] = 0;
            }
        } else if (k == 1) {
            for (int i = 0; i < n - 1; ++i) {
                DP[i][i + 1] = m[i].first * m[i].second * m[i + 1].second;
            }
        } else {
            for (int i = 0; i < n - k; ++i) {
                for (int j = i; j < i + k; ++j) {
                    DP[i][i + k] = min(DP[i][i + k], DP[i][j] + DP[j + 1][i + k] + m[i].first * m[j].second * m[i + k].second);
                }
            }
        }
    }
    cout << DP[0][n - 1] << '\n';
}