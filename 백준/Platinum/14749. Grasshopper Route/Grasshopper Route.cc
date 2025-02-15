#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
const int MAX=1e5+1;
vector<int> adj[MAX],T[MAX],ans;
int N,s,t;
bool middle[MAX],checked[MAX];
bool dfs(int now,int par=0){
	bool ret=false;
	int idx=0;
	for(int i=0;i<adj[now].size();++i){
		int e=adj[now][i];
		if(e==par) continue;
		T[now].push_back(e);
		if(dfs(e,now)||e==t) {
			ret=true;
			idx=T[now].size()-1;
		}
	}
	if(ret) middle[now]=true;
	if(ret) swap(T[now][idx],T[now].back());
	return ret;
}
void solve(int n){
	ans.push_back(n);
	if(T[n].empty()) return;
	int idx=-1;
	for(auto e:T[n]){
		if(T[e].empty()){
			ans.push_back(e);
			continue;
		}
		if(middle[n]&&middle[e]){
			idx=e;
			continue;
		}
		for(auto f:T[e]) solve(f);
		ans.push_back(e);
	}
	if(idx!=-1) solve(idx);
}
int main(){
	cin>>N;
	for(int i=0;i<N-1;++i){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin>>s>>t;
	dfs(s);
	solve(s);
	for(auto e:ans){
		if(checked[e]) continue;
		if(e==t) continue;
		checked[e]=true;
		cout<<e<<'\n';
	}
	cout<<t;
}
