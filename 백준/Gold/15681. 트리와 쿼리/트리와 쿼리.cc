#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, R, Q;
vector<int> adj[100001];
vector<int> ans;
int dfs(int u, int p) {
    int cnt = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        cnt += dfs(v, u);
    }
    return ans[u] = cnt;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> R >> Q;
    ans.resize(N + 1);
    ;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(R, -1);
    int q;
    while (Q--) {
        cin >> q;
        cout << ans[q] << '\n';
    }
}