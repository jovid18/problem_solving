#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int MAXN = 2e5 + 5;

vector<vector<int>> adj(MAXN);
int ans = -1;

int dfs(int v, int p = -1) {
    int res = 1;
    vector<int> d;
    for (int u : adj[v]) {
        if (u == p) continue;
        d.push_back(dfs(u, v));
    }
    sort(d.begin(), d.end(), greater<int>());
    if (d.size() >= 3) {
        res = d[0] + d[1] + d[2] + 1;
        if (d.size() >= 4) {
            ans = max(ans, res + d[3]);
        }
    }
    if (d.size() >= 1) {
        if (d[0] > 1) ans = max(ans, d[0] + 1);
    }
    return res;
}

// https://atcoder.jp/contests/abc394/tasks/abc394_f
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << ans;
}