#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
using Edge=pair<char, pair<int,int>>;
vector<Edge> G;
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
bool comp(const Edge &a,const Edge &b){
	return a.first>b.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>n>>m>>k){
		if(n==0&&m==0&&k==0) break;
		G.clear();
		G.resize(m);
		for(int i=0;i<m;++i){
			char c;
			int v,w;
			cin>>c>>v>>w;
			G[i]=Edge(c,{v,w});
		}
		int lb=0,sb=0;
		sort(G.begin(),G.end());
		UnionFind B(n+1);
		for(int i=0;i<m;++i){
			int u=G[i].second.first;
			int v=G[i].second.second;
			if(B.issame(u,v)) continue;
			if(G[i].first=='B') lb++;
			B.unite(u,v);
		}
		sort(G.begin(),G.end(),comp);
		UnionFind R(n+1);
		for(int i=0;i<m;++i){
			int u=G[i].second.first;
			int v=G[i].second.second;
			if(R.issame(u,v)) continue;
			if(G[i].first=='B') sb++;
			R.unite(u,v);
		}
		if(sb<=k&&k<=lb) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
}
