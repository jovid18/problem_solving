#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            g[u].push_back(v);
        }
    }
    int d[n + 1];
    fill(d, d + n + 1, -1);
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto e : g[x]) {
            if (d[e] == -1) {
                d[e] = d[x] + 1;
                q.push(e);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << d[i] << endl;
    }
}