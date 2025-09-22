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
        cnt = n;
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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v(41, vector<bool>(41, 0));
    int tot = n * (n - 1) / 2;
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    cout << dsu.cnt - 1;
}