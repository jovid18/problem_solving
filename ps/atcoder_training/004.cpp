#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // n이 사람, m이 노래
    // m <= 100
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &v : a)
        for (auto &i : v) cin >> i;

    int ans = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += max(a[k][i], a[k][j]);
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}