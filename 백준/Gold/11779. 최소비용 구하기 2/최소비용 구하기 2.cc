#include <iostream>
#include <vector>
using namespace std;
struct Edge{
	int to;
	int w;
	Edge(int to, int w):to(to), w(w){}
};
const int MAX=1000000000;
using Graph=vector<vector<Edge>>;
Graph graph;
vector<bool> checked;
vector<int> dist;
vector<int> from;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	graph.resize(N+1);
	checked.assign(N+1,false);
	dist.assign(N+1,MAX);
	from.assign(N+1,-1);
	for(int i=0;i<M;++i){
		int a,b,w;
		cin>>a>>b>>w;
		graph[a].push_back(Edge(b,w));
	}
	int s,f;
	cin>>s>>f;
	dist[s]=0;
	for(int i=0;i<N;++i){
		int min_dist=MAX;
		int min_v=-1;
		for(int v=1;v<=N;++v){
			if(!checked[v]&&dist[v]<min_dist){
				min_dist=dist[v];
				min_v=v;
			}
		}
		if(min_v==-1){
			break;
		}
		for(auto e: graph[min_v]){
			if(dist[e.to]>dist[min_v]+e.w){
				dist[e.to]=dist[min_v]+e.w;
				from[e.to]=min_v;
			}
		}
		checked[min_v]=true;
	}
	cout<<dist[f]<<endl;
	vector<int> answer;
	int last=f;
	answer.push_back(last);
	while(last!=s){
		last=from[last];
		answer.push_back(last);
	}
	cout<<answer.size()<<endl;
	for(auto iter=answer.rbegin();iter!=answer.rend();iter++){
		cout<<*iter<<" ";
	}
	
}