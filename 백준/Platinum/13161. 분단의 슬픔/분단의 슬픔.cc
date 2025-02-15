#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V=503,INF=1e9;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int work[MAX_V];
int level[MAX_V];
int visited[MAX_V];
vector<int> adj[MAX_V];
int N,S=501,T=502;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;++i){
		int x;
		cin>>x;
		if(x==1){
			c[S][i]=INF;
			adj[S].push_back(i);
			adj[i].push_back(S);
		}else if(x==2){
			c[i][T]=INF;
			adj[T].push_back(i);
			adj[i].push_back(T);
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>c[i][j];
			if(i!=j) adj[i].push_back(j);
		}
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
	cout<<ans<<'\n';
	queue<int> Q;
	Q.push(S);
	visited[S]=1;
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(auto e:adj[now]){
			if(visited[e]) continue;
			if(c[now][e]>f[now][e]){
				Q.push(e);
				visited[e]=1;
			}
		}
	}
	vector<int> a,b;
	for(int i=1;i<=N;++i){
		if(visited[i]) a.push_back(i);
		else b.push_back(i);
	}
	for(auto e: a) cout<<e<<" ";
	cout<<'\n';
	for(auto e: b) cout<<e<<" ";
	cout<<'\n';
}
