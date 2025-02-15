#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V=302,INF=1e9;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int work[MAX_V];
int level[MAX_V];
vector<int> adj[MAX_V];
int N,K,D;
int S=0,T=301;
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
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K>>D;
	for(int i=1;i<=N;++i){
		c[S][i]=K;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=1;i<=D;++i){
		int fmax;
		cin>>fmax;
		c[200+i][T]=fmax;
		adj[200+i].push_back(T);
		adj[T].push_back(200+i);
	}
	for(int i=1;i<=N;++i){
		int count;
		cin>>count;
		for(int j=1;j<=count;++j){
			int fnum;
			cin>>fnum;
			c[i][fnum+200]=1;
			adj[i].push_back(fnum+200);
			adj[fnum+200].push_back(i);
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
	cout<<ans;
}
