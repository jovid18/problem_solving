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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu;
    dsu.init(n);
    vector<pair<int, pair<int, int>>> edges, mst;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto [w, uv] : edges) {
        auto [u, v] = uv;
        if (dsu.unite(u, v)) {
            mst.push_back({w, {u, v}});
            cost += w;
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        auto [w, uv] = mst.back();
        mst.pop_back();
        cost -= w;
    }
    cout << cost;
}