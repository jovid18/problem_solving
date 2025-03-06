#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int MOD = 10000;
int DP[101][3];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n, -1);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a] = b;
    }
    if (v[0] != -1) {
        DP[0][v[0]] = 1;
    } else {
        DP[0][0] = DP[0][1] = DP[0][2] = 1;
    }
    if (v[1] != -1) {
        DP[1][v[1]] = DP[0][0] + DP[0][1] + DP[0][2];
    } else {
        DP[1][0] = DP[1][1] = DP[1][2] = DP[0][0] + DP[0][1] + DP[0][2];
    }
    for (int idx = 2; idx < n; ++idx) {
        // [i][j][k]
        for (int k = 0; k < 3; ++k) {
            if (v[idx] != -1 && v[idx] != k) {
                continue;
            }
            for (int j = 0; j < 3; ++j) {
                if (j != k) {
                    DP[idx][k] += DP[idx - 1][j];
                    DP[idx][k] %= MOD;
                }
                for (int i = 0; i < 3; ++i) {
                    if (i == j && j == k) {
                        continue;
                    }
                    if (j == k && i != j && DP[idx - 1][j]) {
                        DP[idx][k] += DP[idx - 2][i];
                        DP[idx][k] %= MOD;
                    }
                }
            }
        }
    }
    cout << (DP[n - 1][0] + DP[n - 1][1] + DP[n - 1][2]) % MOD << '\n';
}