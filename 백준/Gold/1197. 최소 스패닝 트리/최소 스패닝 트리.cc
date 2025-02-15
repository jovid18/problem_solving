#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
using Edge=pair<int, pair<int,int>>;
vector<Edge> edges;

struct UnionFind {
	vector<int> par, siz;
	UnionFind(int n): par(n,-1),siz(n,1) {}
	int root(int x){
		if(par[x]==-1) return x;
		else return par[x]=root(par[x]);
	}
	
	bool issame(int x, int y){
		return root(x)==root(y);
	}
	
	bool unite(int x, int y){
		x=root(x);
		y=root(y);
		if(x==y) return false;
		if(siz[x]<siz[y]) swap (x,y);
		par[y]=x;
		siz[x]+=siz[y];
		return true;
	}
};

int main(){
	cin>>N>>M;
	edges.resize(M);
	for(int i=0;i<M;++i){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i]=Edge(w,{u,v});
	}
	sort(edges.begin(),edges.end());
	int ans=0;
	UnionFind uf(N+1);
	for(int i=0;i<M;++i){
		int w=edges[i].first;
		int u=edges[i].second.first;
		int v=edges[i].second.second;
		if(uf.issame(u,v)) continue;
		ans+=w;
		uf.unite(u,v);
	}
	cout<<ans;
}
