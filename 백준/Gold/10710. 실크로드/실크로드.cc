#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1e18;
// DP[i][j] : i번째 도시까지 j일 안에 도착할 수 있는 최소 비용
int DP[1001][1001];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // n : city, m : day
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, 0), cond(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> cond[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            DP[i][j] = INF;
        }
    }
    for (int j = 0; j <= m; j++) DP[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + dist[i] * cond[j]);
            DP[i][j] = min(DP[i][j], DP[i][j - 1]);
        }
    }
    cout << DP[n][m] << '\n';
}