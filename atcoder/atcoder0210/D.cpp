#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
const int MAX = 2e5 + 1;
int N, a, b, x;
vector<pii> G[MAX];
int cost[MAX];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    cost[s] = 0;
    
    while (!pq.empty()) {
        int now = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();
        
        if (cost[now] < nowcost) continue;
        
        for (auto e : G[now]) {
            int next = e.first;
            int nextcost = nowcost + e.second;
            
            if (nextcost < cost[next]) {
                cost[next] = nextcost;
                pq.push({nextcost, next});
            }
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cost[i] = 1LL << 62;
    }
    for (int i = 1; i < N; ++i) {
        cin >> a >> b >> x;
        G[i].push_back({i + 1, a});
        G[i].push_back({x, b});
    }
    dijkstra(1);
    cout << cost[N] << "\n";
}
