#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
using Edge=pair<int,pair<int,int>>;
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
int N;
vector<pair<int,int>> PX;
vector<pair<int,int>> PY;
vector<pair<int,int>> PZ;
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int x,y,z;
		cin>>x>>y>>z;
		PX.push_back({x,i});
		PY.push_back({y,i});
		PZ.push_back({z,i});
	}
	sort(PX.begin(),PX.end());
	sort(PY.begin(),PY.end());
	sort(PZ.begin(),PZ.end());
	for(int i=0;i<N-1;++i){
		edges.push_back(Edge(abs(PX[i+1].first-PX[i].first),{PX[i+1].second,PX[i].second}));
		edges.push_back(Edge(abs(PY[i+1].first-PY[i].first),{PY[i+1].second,PY[i].second}));
		edges.push_back(Edge(abs(PZ[i+1].first-PZ[i].first),{PZ[i+1].second,PZ[i].second}));
	}
	sort(edges.begin(),edges.end());
	int ans=0;
	int M=edges.size();
	UnionFind uf(N);
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
	