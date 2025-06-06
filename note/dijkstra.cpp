#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int v, e;
    cin >> v >> e;

    vector<vector<pii>> G(v);
    vector<int> cost(v, LLONG_MAX);

    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    auto dijkstra = [&](int s) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        cost[s] = 0;

        while (!pq.empty()) {
            int now_v = pq.top().second;
            int now_c = pq.top().first;
            pq.pop();

            if (cost[now_v] < now_c) continue;

            for (auto e : G[now_v]) {
                int next_v = e.first;
                int next_c = now_c + e.second;

                if (next_c < cost[next_v]) {
                    cost[next_v] = next_c;
                    pq.push({next_c, next_v});
                }
            }
        }
    };

    int start;
    cin >> start;
    dijkstra(start);
}
