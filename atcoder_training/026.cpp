#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc138/tasks/abc138_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> cnt(n);
    for (int i = 0; i < q; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        cnt[p] += x;
    }
    function<void(int, int)> dfs = [&](int s, int p) {
        for (auto u : a[s]) {
            if (u == p) continue;
            tree[s].push_back(u);
            dfs(u, s);
        }
    };
    dfs(0, -1);
    function<void(int, int)> update = [&](int s, int p) {
        for (auto u : tree[s]) {
            if (u == p) continue;
            cnt[u] += cnt[s];
            update(u, s);
        }
    };
    update(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << cnt[i] << ' ';
    }
}