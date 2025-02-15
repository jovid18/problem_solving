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
Graph graph(1001);
vector<bool> checked(1001,false);
vector<int> dist(1001,MAX);
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,w;
		cin>>a>>b>>w;
		graph[a].push_back(Edge(b,w));
	}
	int s,f;
	cin>>s>>f;
	dist[s]=0;
	for(int i=-0;i<N;++i){
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
			}
		}
		checked[min_v]=true;
		if(checked[f]){
			break;
		}
	}
	cout<<dist[f];
	
}