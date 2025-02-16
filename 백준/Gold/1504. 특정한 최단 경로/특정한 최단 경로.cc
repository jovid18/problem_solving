#include <iostream>
#include <vector>
using namespace std;

const int INF=10000000;
template<class T> bool chmin(T &a, T b){
	if(a>b){
		a=b;
		return true;
	}
	else return false;
}

class Edge{
	public:
	int to;
	int w;
	Edge(int to, int w): to(to), w(w){}
};

int main(){
	int N, M;
	int first, second;
	cin>>N>>M;
	vector<vector<Edge>> G(N+1);
	for(int i=0;i<M;++i){
		int a,b,w;
		cin>>a>>b>>w;
		G[a].push_back(Edge(b,w));
		G[b].push_back(Edge(a,w));
	}
	cin>>first>>second;
	vector<bool> check(N+1,false);
	vector<int> dist(N+1,INF);
	dist[1]=0;
	for(int i=1;i<=N;++i){
		int min_dist=INF;
		int min_v=-1;
		for(int v=1;v<=N;++v){
			if(!check[v]&&dist[v]<min_dist){
				min_dist=dist[v];
				min_v=v;
			}
		}
		if(min_v==-1) break;
		for(auto e:G[min_v]){
			chmin(dist[e.to],dist[min_v]+e.w);
		}
		check[min_v]=true;
	}
	int d1F=dist[first];
	int d1S=dist[second];
	check.assign(N+1,false);
	dist.assign(N+1,INF);
	dist[N]=0;
	for(int i=1;i<=N;++i){
		int min_dist=INF;
		int min_v=-1;
		for(int v=1;v<=N;++v){
			if(!check[v]&&dist[v]<min_dist){
				min_dist=dist[v];
				min_v=v;
			}
		}
		if(min_v==-1) break;
		for(auto e:G[min_v]){
			chmin(dist[e.to],dist[min_v]+e.w);
		}
		check[min_v]=true;
	}
	int dSN=dist[second];
	int dFN=dist[first];
	check.assign(N+1,false);
	dist.assign(N+1,INF);
	dist[first]=0;
	for(int i=1;i<=N;++i){
		int min_dist=INF;
		int min_v=-1;
		for(int v=1;v<=N;++v){
			if(!check[v]&&dist[v]<min_dist){
				min_dist=dist[v];
				min_v=v;
			}
		}
		if(min_v==-1) break;
		for(auto e:G[min_v]){
			chmin(dist[e.to],dist[min_v]+e.w);
		}
		check[min_v]=true;
	}
	int dFS=dist[second];
	int way1=d1F+dFS+dSN;
	int way2=d1S+dFS+dFN;
	if(way1>=INF&&way2>=INF){
		cout<<-1<<endl;;
	}else{
		if(way1>way2){
			cout<<way2<<endl;
		}else{
			cout<<way1<<endl;
		}
	}
	
}