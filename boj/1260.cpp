#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> color;
queue<int> q;
vector<bool> check;
void DFS(const vector<vector<int>> &graph, int i) {
    cout << i << " ";
    color[i] = 0;
    for (auto e : graph[i]) {
        if (color[e] == -1) {

            DFS(graph, e);
        }
    }
    color[i] = 1;
}
void BFS(const vector<vector<int>> &graph, int i) {
    color[i] = 0;
    q.push(i);
    vector<int> bfs;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (check[u] == false) {
            cout << u << " ";
        }
        check[u] = true;

        bfs.push_back(u);
        for (auto v : graph[u]) {
            if (color[v] == -1) {
                color[v] == 0;
                q.push(v);
            }
        }
        color[u] = 1;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int start;
    cin >> start;
    vector<vector<int>> graph(N + 1);
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (auto iter = graph.begin(); iter != graph.end(); iter++) {
        sort((*iter).begin(), (*iter).end());
    }

    color.assign(N + 1, -1);
    DFS(graph, start);
    cout << endl;
    color.assign(N + 1, -1);
    check.assign(N + 1, false);
    BFS(graph, start);
}