#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;
int g[10][10];

// https://atcoder.jp/contests/abc396/tasks/abc396_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            g[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u][v] = w;
        g[v][u] = w;
    }
    // 0 -> {v} -> n-1
    if (n == 2) {
        cout << g[0][1];
        return 0;
    }
    int ans = g[0][n - 1];
    vector<int> perm;
    for (int i = 0; i < n; i++) {
        perm.push_back(i);
    }
    do {
        if (perm[0] != 0) continue;
        int idx = find(perm.begin(), perm.end(), n - 1) - perm.begin();
        int x = 0;
        bool pos = true;
        for (int i = 0; i < idx; i++) {
            if (g[perm[i]][perm[i + 1]] == INF) {
                pos = false;
                break;
            }
            x ^= g[perm[i]][perm[i + 1]];
        }
        if (pos) ans = min(ans, x);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans;
}