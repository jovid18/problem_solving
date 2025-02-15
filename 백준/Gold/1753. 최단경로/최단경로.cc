#include <iostream>
#include <vector>
#include <queue>;
using namespace std;
const int MAX=1000000000;
vector<vector<pair<int,int>>> graph(20001);
int N,M,start;
vector<int> dist(20001,MAX);

void mindist(int start){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,start});
	dist[start]=0;
	while(!pq.empty()){
		int distance = pq.top().first; 
        int now = pq.top().second; 
        pq.pop();
        
        if(dist[now]<distance)
            continue;
        
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = distance+graph[now][i].second; 
            if(cost<dist[graph[now][i].first])
            {
                dist[graph[now][i].first]=cost;
                pq.push(make_pair(cost,graph[now][i].first));
            }
        }
	}
}



int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M>>start;
	for(int i=0;i<M;++i){
		int a,b,w;
		cin>>a>>b>>w;
		graph[a].push_back({b,w});
	};
	mindist(start);
	for(int i=1;i<=N;++i){
		if(dist[i]==MAX){
			cout<<"INF"<<'\n';
		}else{
			cout<<dist[i]<<'\n';
		}
		
	}
	
}
