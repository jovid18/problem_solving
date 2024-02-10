
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