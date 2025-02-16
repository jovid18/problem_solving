#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
struct boom{
	int u,v,w;
};
int N,M;
vector<vector<int>> adj;
vector<int> par;
vector<int> orig;
vector<bool> visited;
vector<boom> ans;
//adj: 인접 리스트, par: 부모 노드, orig: 추가된 vertex의 원래 번호
int root(int x){
	return par[x]=(x==par[x]?x:root(par[x]));
}
int dfs(int i){
	visited[i]=true;
	int now=-1;
	for(int j:adj[i]){
		if(visited[j]) continue;
		int k=dfs(j);
		if(k!=-1) ans.push_back({i,j,k});
		else{
			if(now==-1) now=j;
			else{
				ans.push_back({now,i,j});
				now=-1;
			}
		}
	}
	return now;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	adj.resize(N+M);
	par.resize(N);
	orig.resize(N+M);
	for(int i=0;i<N;++i){
		par[i]=i;
		orig[i]=i;
	}
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if(root(a)==root(b)){
			orig[N]=b;
			b=N++;
		}else{
			par[root(a)]=root(b);
		}
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited.resize(N);
	for(int i=0;i<N;++i){
		if(visited[i]) continue;
		dfs(i);
	}
	cout<<ans.size()<<'\n';
	for(auto e:ans){
		cout<<orig[e.u]+1<<" "<<orig[e.v]+1<<" "<<orig[e.w]+1<<'\n';
	}
}