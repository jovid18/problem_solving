#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
vector<int> result;
vector<int> indegree;
vector<vector<int>> graph;

void topologicalSort() {
    priority_queue<int,vector<int>,greater<int>> q;  
    for (int i=1; i<=N; i++) {
        if (indegree[i]==0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        result.push_back(cur);
        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (indegree[next]==0) q.push(next);
        }
    }
}

int main() {
    cin>>N>>M;
    indegree.assign(N+1,0);
    graph.resize(N+1);
    for (int i=0; i<M; i++) {
    	int u,v;
    	cin>>u>>v;
    	graph[u].push_back(v);
    	indegree[v]++;
    }
    topologicalSort();
    for (auto x : result) {
    	cout<<x<<'\n';
    }
}