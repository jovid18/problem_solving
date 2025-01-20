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
        for (int i = 0; i < n; i++) {
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

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pii> F(m1), G(m2);
    vector<bool> isDeleted(m1);
    DSU DSUG;
    DSUG.init(n);
    DSU DSUF;
    DSUF.init(n);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        F[i] = {u, v};
    }
    int ans = 0;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        G[i] = {u, v};
        DSUG.unite(u, v);
    }
    for (int i = 0; i < m1; i++) {
        int u = F[i].first, v = F[i].second;
        if (DSUG.find(u) != DSUG.find(v)) {
            ans++;
        } else {
            DSUF.unite(u, v);
        }
    }
    // cout << ans << ' ' << DSUF.cnt << ' ' << DSUG.cnt << '\n';
    cout << ans + DSUF.cnt - DSUG.cnt << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}