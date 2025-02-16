#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
const int VMAX=300;
int S=VMAX-2;
int T=VMAX-1;
int NMAX=100;
int INF=1e9;
int BMAX=0,CMIN=0;
vector<int> adj[VMAX];
int c[VMAX][VMAX];
int f[VMAX][VMAX];
int d[VMAX][VMAX];
void input(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1+NMAX;i<=N+NMAX;++i){
		int bookneed;
		cin>>bookneed;
		c[i][T]=bookneed;
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	for(int i=1;i<=M;++i){
		int bookhave;
		cin>>bookhave;
		c[S][i]=bookhave;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=1;i<=M;++i){
		for(int j=1+NMAX;j<=N+NMAX;++j){
			int capacity;
			cin>>capacity;
			c[i][j]=capacity;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	for(int i=1;i<=M;++i){
		for(int j=1+NMAX;j<=N+NMAX;++j){
			int cost;
			cin>>cost;
			d[i][j]=cost;
			d[j][i]=-cost;
		}
	}
}
void solve(){
	while(1){
		int prev[VMAX],dist[VMAX];
		fill(prev,prev+VMAX,-1);
		fill(dist,dist+VMAX,INF);
		bool inq[VMAX];
		queue<int> q;
		dist[S]=0;
		inq[S]=true;
		q.push(S);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			inq[now]=false;
			for(auto next:adj[now]){
				if(c[now][next]>f[now][next]&&dist[next]>dist[now]+d[now][next]){
					dist[next]=dist[now]+d[now][next];
					prev[next]=now;
					if(!inq[next]){
						q.push(next);
						inq[next]=true;
					}
				}
			}
		}
		if(prev[T]==-1) break;
		int flow=INF;
		for(int i=T;i!=S;i=prev[i]) flow=min(flow,c[prev[i]][i]-f[prev[i]][i]);
		for(int i=T;i!=S;i=prev[i]){
			CMIN+=flow*d[prev[i]][i];
			f[prev[i]][i]+=flow;
			f[i][prev[i]]-=flow;
		}
		BMAX+=flow;
	}
	cout<<BMAX<<'\n'<<CMIN;
}
int main(){
	input();
	solve();
}
