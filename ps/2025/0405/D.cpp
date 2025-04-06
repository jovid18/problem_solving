#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int INF = 1e18;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int encode(pii p) { return p.first * 1001 + p.second; }
pii decode(int x) { return {x / 1001, x % 1001}; }

// https://atcoder.jp/contests/abc400/tasks/abc400_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    pii s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    s.first--, s.second--;
    t.first--, t.second--;
    vector<vector<pii>> g(1001 * 1001, vector<pii>());
    auto isIn = [&](int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; };
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!isIn(nx, ny)) continue;
                if (a[nx][ny] == '.') {
                    g[encode({i, j})].push_back({encode({nx, ny}), 0});
                }
            }

            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                int mx = i + 2 * dx[k];
                int my = j + 2 * dy[k];
                if (isIn(nx, ny)) {
                    if (a[nx][ny] == '#') {
                        g[encode({i, j})].push_back({encode({nx, ny}), 1});
                    }
                }
                if (isIn(mx, my)) {
                    g[encode({i, j})].push_back({encode({mx, my}), 1});
                }
            }
        }
    }
    vector<int> dist(1001 * 1001, INF);
    deque<pair<int, int>> dq;
    dist[encode(s)] = 0;
    dq.push_front({encode(s), 0});
    while (!dq.empty()) {
        auto [v, d] = dq.front();
        dq.pop_front();
        if (dist[v] < d) continue;
        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                if (w == 0) {
                    dq.push_front({u, dist[u]});
                } else {
                    dq.push_back({u, dist[u]});
                }
            }
        }
    }
    cout << dist[encode(t)] << '\n';
}
