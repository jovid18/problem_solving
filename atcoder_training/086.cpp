#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

struct DSU {
    vector<int> par, sz;
    int cnt = 0;
    DSU() {}
    void init(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
        cnt = n;
    }
    int find(int x) { return x == par[x] ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        if (sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        sz[u] = 0;
        par[u] = par[v];
        cnt--;
        return true;
    }
};

// https://atcoder.jp/contests/abc075/tasks/abc075_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    for (auto &[u, v] : edges) cin >> u >> v;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        DSU dsu;
        dsu.init(n);
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            dsu.unite(edges[j].first, edges[j].second);
        }
        if (dsu.cnt != 1) ans++;
    }
    cout << ans;
}