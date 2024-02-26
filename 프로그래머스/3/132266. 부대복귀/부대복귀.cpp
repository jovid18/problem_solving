#include <queue>
#include <string>
#include <vector>
using namespace std;
int dist[100001];
vector<int> adj[100001];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources,
                     int destination) {
    for (int i = 1; i <= n; i++)
        dist[i] = 1e9;
    for (auto e : roads) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : adj[cur]) {
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    vector<int> answer;
    for (auto e : sources) {
        if (dist[e] != 1e9)
            answer.push_back(dist[e]);
        else
            answer.push_back(-1);
    }
    return answer;
}