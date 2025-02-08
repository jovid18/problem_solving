#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

struct Edge {
    int u, v;
    bool isUsed;
};

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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    DSU dsu;
    dsu.init(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, true});
        if (!dsu.unite(u, v)) {
            edges.back().isUsed = false;
        }
    }
    cout << dsu.cnt - 1 << endl;
    set<int> leader;
    for (int i = 1; i <= N; ++i) {
        if (dsu.find(i) == i) {
            leader.insert(i);
        }
    }
    for (int i = 0; i < M; ++i) {
        if (dsu.cnt == 1) break;
        if (edges[i].isUsed) continue;
        if (dsu.find(edges[i].u) == dsu.find(edges[i].v)) {
            int x = 0;
            int rootU = dsu.find(edges[i].u);
            for (int l : leader) {
                if (dsu.find(edges[i].u) != l) {
                    x = l;
                    break;
                }
            }
            dsu.unite(edges[i].u, x);
            int rootX = dsu.find(x);
            if (rootX != x) {
                leader.erase(x);
            }
            if (rootU != dsu.find(edges[i].u)) {
                leader.erase(rootU);
            }
            cout << i + 1 << ' ' << edges[i].u << " " << x << '\n';
        }
    }
}