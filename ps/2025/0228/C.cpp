#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<bool> used;
vector<bool> visited;

vector<int> getPath(int st, int en, const vector<vector<int>>& adj) {
    int n = (int)adj.size() - 1;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == en) break;

        for (int nx : adj[u]) {
            if (!visited[nx]) {
                visited[nx] = true;
                parent[nx] = u;
                q.push(nx);
            }
        }
    }

    vector<int> path;
    if (!visited[en]) {
        return path;
    }
    for (int cur = en; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

// 후위 순회
void dfs(int u, const vector<vector<int>>& adj) {
    visited[u] = true;
    if (used[u]) {
        for (int v : adj[u]) {
            if (used[v]) continue;
            if (!visited[v]) {
                dfs(v, adj);
            }
        }
        ans.push_back(u);
        for (int v : adj[u]) {
            if (!used[v]) continue;
            if (!visited[v]) {
                dfs(v, adj);
            }
        }
    } else {
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj);
            }
        }
        ans.push_back(u);
    }
}

// https://codeforces.com/contest/2071/problem/C
void solve() {
    int n, s, e;
    cin >> n >> s >> e;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto path = getPath(s, e, adj);
    used.clear();
    used.assign(n + 1, false);
    visited.clear();
    visited.assign(n + 1, false);
    ans.clear();
    for (int i = 0; i < path.size(); i++) {
        used[path[i]] = true;
    }
    dfs(s, adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
