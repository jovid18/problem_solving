#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

struct DSU {
    vector<int> par, sz;
    int cnt;
    DSU() {}
    void init(int n) {
        cnt = n;
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

// https://atcoder.jp/contests/abc393/tasks/abc393_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    set<pii> edges;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            ans++;
            continue;
        }
        if (a > b) swap(a, b);
        if (edges.count({a, b})) {
            ans++;
            continue;
        } else {
            edges.insert({a, b});
        }
    }
    cout << ans;
}