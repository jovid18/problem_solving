#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
const int VMAX=1000;
int S=VMAX-2;
int T=VMAX-1;
int NMAX=400;
int INF=1e9;
int WMAX=0,CMAX=0;
vector<int> adj[VMAX];
int c[VMAX][VMAX];
int f[VMAX][VMAX];
int d[VMAX][VMAX];
void input(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		c[S][i]=1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=1+NMAX;i<=M+NMAX;++i){
		c[i][T]=1;
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	for(int i=1;i<=N;++i){
		int works;
		cin>>works;
		while(works--){
			int no, cost;
			cin>>no>>cost;
			c[i][no+NMAX]=1;
			adj[i].push_back(no+NMAX);
			adj[no+NMAX].push_back(i);
			d[i][no+NMAX]=cost;
			d[no+NMAX][i]=-cost;
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
			CMAX+=flow*d[prev[i]][i];
			f[prev[i]][i]+=flow;
			f[i][prev[i]]-=flow;
		}
		WMAX++;
	}
	cout<<WMAX<<'\n'<<CMAX;
}
int main(){
	input();
	solve();
}
