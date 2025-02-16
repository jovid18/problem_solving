#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
using Edge=pair<double, pair<double,double>>;
vector<pair<double,double>> point;
vector<Edge> edges;
double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
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
	cin>>N;
	for(int i=0;i<N;++i){
		double a,b;
		cin>>a>>b;
		point.push_back({a,b});
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			double w=dist(point[i].first,point[i].second,point[j].first,point[j].second);
			edges.push_back({w,{i,j}});
		}
	}
	sort(edges.begin(),edges.end());
	double ans=0;
	UnionFind uf(N);
	for(int i=0;i<edges.size();++i){
		double w=edges[i].first;
		int u=edges[i].second.first;
		int v=edges[i].second.second;
		if(uf.issame(u,v)) continue;
		ans+=w;
		uf.unite(u,v);
	}
	cout<<ans;
}
