#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;

// https://atcoder.jp/contests/abc012/tasks/abc012_4
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, INF));
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        s--, t--;
        g[s][t] = d;
        g[t][s] = d;
    }
    for (int i = 0; i < v; ++i) g[i][i] = 0;
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            if (g[i][k] == INF) continue;
            for (int j = 0; j < v; ++j) {
                if (g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int min_dist = INF;
    for (int i = 0; i < v; ++i) {
        int now_max_dist = -1;
        for (int j = 0; j < v; ++j) {
            now_max_dist = max(now_max_dist, g[i][j]);
        }
        if (now_max_dist < min_dist) {
            min_dist = now_max_dist;
        }
    }
    cout << min_dist << '\n';
}