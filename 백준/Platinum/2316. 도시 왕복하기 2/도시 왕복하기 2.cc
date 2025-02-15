#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V=801,INF=1e9,DIV=400;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int work[MAX_V];
int level[MAX_V];
vector<int> adj[MAX_V];
int N,P;
int S=401,T=2;
bool bfs(){
	fill(level,level+MAX_V,-1);
	level[S]=0;
	queue<int> q;
	q.push(S);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto e:adj[now]){
			if(level[e]==-1&&c[now][e]>f[now][e]){
				level[e]=level[now]+1;
				q.push(e);
			}
		}
	}
	return level[T]!=-1;
}
int dfs(int now,int flow){
	if(now==T){
		return flow;
	}
	for(int &i=work[now];i<adj[now].size();++i){
		int next=adj[now][i];
		if(level[next]==level[now]+1&&c[now][next]-f[now][next]>0){
			int ret= dfs(next,min(c[now][next]-f[now][next],flow));
			if(ret>0){
				f[now][next]+=ret;
				f[next][now]-=ret;
				return ret;
			}
		}
	}
	return 0;
}

int main(){
	cin>>N>>P;
	for(int i=1;i<=N;++i){
		c[i][i+DIV]=1;
		adj[i].push_back(i+DIV);
		adj[i+DIV].push_back(i);
	}
	for(int i=1;i<=P;++i){
		int a,b;
		cin>>a>>b;
		c[a+DIV][b]=1;
		c[b+DIV][a]=1;
		adj[a+DIV].push_back(b);
		adj[b].push_back(a+DIV);
		adj[b+DIV].push_back(a);
		adj[a].push_back(b+DIV);
	}
	int ans=0;
	while(bfs()){
		fill(work,work+MAX_V,0);
		while(1){
			int flow=dfs(S,INF);
			if(flow==0) break;
			ans+=flow;
		}
	}
	cout<<ans;
}
