#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, INF));
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s][t] = d;
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

    for (int i = 0; i < v; ++i) {
        if (g[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            cout << (g[i][j] == INF ? "INF" : to_string(g[i][j])) << (j == v - 1 ? "\n" : " ");
        }
    }
}