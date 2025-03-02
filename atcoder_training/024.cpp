#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int idx, k;
        cin >> idx >> k;
        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;
            adj[idx].push_back(c);
        }
    }
    vector<bool> vis(n + 1);
    vector<int> in(n + 1), out(n + 1);
    int t = 0;
    function<void(int)> dfs = [&](int s) {
        ++t;
        in[s] = t;
        vis[s] = true;
        for (auto u : adj[s]) {
            if (!vis[u]) {
                dfs(u);
            }
        }
        ++t;
        out[s] = t;
    };
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ' << in[i] << ' ' << out[i] << '\n';
    }
}