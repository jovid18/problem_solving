#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int edge[101][101];

// https://atcoder.jp/contests/abc398/tasks/abc398_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge[u][v] = edge[v][u] = 1;
    }
    vector<bool> red(n + 1);
    function<void(int, int, int)> dfs = [&](int u, int p, bool is_red) {
        red[u] = is_red;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u, !is_red);
        }
    };
    red[1] = 1;
    dfs(1, 1, 1);
    int cnt_red = count(red.begin(), red.end(), 1);
    int cnt_blue = n - cnt_red;
    int expectedEdges = cnt_blue * cnt_red;
    int nowEdges = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (edge[i][j] && red[i] != red[j]) {
                nowEdges++;
            }
        }
    }
    if ((expectedEdges - nowEdges) % 2) {
        cout << "First" << endl;
        int x, y;
        while (true) {
            for (int i = 1; i <= n; ++i) {
                bool found = 0;
                for (int j = i + 1; j <= n; ++j) {
                    if (red[i] != red[j] && !edge[i][j]) {
                        cout << i << ' ' << j << endl;
                        edge[i][j] = edge[j][i] = 1;
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
            cin >> x >> y;
            if (x == -1 && y == -1) {
                return 0;
            } else {
                edge[x][y] = edge[y][x] = 1;
            }
        }
    } else {
        cout << "Second" << endl;
        int x, y;
        while (true) {
            cin >> x >> y;
            if (x == -1 && y == -1) {
                return 0;
            } else {
                edge[x][y] = edge[y][x] = 1;
            }
            for (int i = 1; i <= n; ++i) {
                bool found = 0;
                for (int j = i + 1; j <= n; ++j) {
                    if (red[i] != red[j] && !edge[i][j]) {
                        cout << i << ' ' << j << endl;
                        edge[i][j] = edge[j][i] = 1;
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
        }
    }
}