#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
vector<int> result;
vector<int> indegree;
vector<vector<int>> graph;

void topologicalSort() {
    queue<int> q;  
    for (int i=0; i<N; i++) {
        if (indegree[i]==0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
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
    indegree.resize(N);
    graph.resize(N);
    for (int i=0; i<M; i++) {
        int P;
        cin>>P;
        int u,v;
        cin>>u;
        for(int k=1;k<P;++k){
        	cin>>v;
        	graph[u-1].push_back(v-1);
        	indegree[v-1]++;
        	u=v;
        } 
    }
    topologicalSort();
    if (result.size() == N) {
        for (auto x : result) {
        	cout<<x+1<<'\n';
        }
    }
    else cout<<0;
}