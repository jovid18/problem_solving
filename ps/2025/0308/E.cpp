#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int BITS = 31;

// https://atcoder.jp/contests/abc396/tasks/abc396_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    vector<int> a(n + 1, -1);
    bool imp = false;
    for (int start = 1; start <= n; start++) {
        // 방문 완료
        if (a[start] != -1) continue;
        a[start] = 0;
        queue<int> q;
        q.push(start);
        // start와 연결된 정점들
        vector<int> comp;
        comp.push_back(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int au = a[u];
            for (auto &[v, z] : g[u]) {
                if (a[v] == -1) {
                    a[v] = au ^ z;
                    q.push(v);
                    comp.push_back(v);
                } else {
                    if (a[v] != (au ^ z)) {
                        imp = true;
                        break;
                    }
                }
            }
            if (imp) break;
        }
        if (imp) break;

        vector<int> avals;
        for (int node : comp) {
            avals.push_back(a[node]);
        }

        int x_opt = 0;
        for (int b = 0; b < BITS; b++) {
            int mask = 1LL << b;
            int cnt1 = 0;
            for (auto val : avals) {
                if (val & mask) cnt1++;
            }
            int cnt0 = avals.size() - cnt1;
            if (cnt1 > cnt0) {
                // flip하면 cnt1 < cnt0 -> cnt1가 작아짐 
                x_opt |= mask;
            }
        }
        for (int node : comp) {
            a[node] = x_opt ^ a[node];
        }
    }

    if (imp) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}