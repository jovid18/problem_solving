#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
vector<vector<int>> adj;
int parent[100001][18]={0};
int level[100001],maxl;
void make_tree(int N, int P,int lvl){
	parent[N][0]=P;
	level[N]=lvl;
	for(int i=1;i<=maxl;++i){
		parent[N][i]=parent[parent[N][i-1]][i-1];
	}
	for(auto e:adj[N]){
		if(e==P) continue;
		make_tree(e,N,lvl+1);
	}
}
int LCA(int a,int b){
	if(a==1|| b==1) return 1;
	if(level[a]<level[b]) swap(a,b);
	if(level[a]!=level[b]){
		for(int i=maxl;i>=0;--i){
			if(level[parent[a][i]]>=level[b]){
				a=parent[a][i];
			}
		}
	}
	int res=a;
	if(a!=b){
		for(int i=maxl;i>=0;--i){
			if(parent[a][i]!=parent[b][i]){
				a=parent[a][i];
				b=parent[b][i];
			}
		}
		res=parent[a][0];
	}
	return res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	adj.resize(n+1);
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	maxl=(int)floor(log2(n+1));
	make_tree(1,0,1);
	cin>>m;
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		cout<<LCA(a,b)<<'\n';
	}
}