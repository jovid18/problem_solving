#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc007/tasks/abc007_3
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    pii s, e;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;
    s.first--, s.second--, e.first--, e.second--;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pii> q;
    q.push(s);
    dist[s.first][s.second] = 0;
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (pii d : dir) {
            int nx = x.first + d.first;
            int ny = x.second + d.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#') {
                continue;
            }
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x.first][x.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[e.first][e.second] << '\n';
}