#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using pii=pair<int,int>;
const int VMAX=206;
vector<pii> V;
int N,M;
int S=VMAX-2;
int T=VMAX-1;
double INF=1e9;
int BMAX=0;
double CMIN=0;
vector<int> adj[VMAX];
int c[VMAX][VMAX];
int f[VMAX][VMAX];
double d[VMAX][VMAX];
pii P[VMAX];
double dist(int i, int j){
	double dx=P[i].first-P[j].first;
	double dy=P[i].second-P[j].second;
	return sqrt(dx*dx+dy*dy)/2;
}
void input(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i].first>>V[i].second;
	}
	for(int i=0;i<N;++i){
		P[i]={(V[i].first),V[i].second};
		P[i+100]={-(V[i].first),V[i].second};
	}
	for(int i=100;i<100+N;++i){
		c[i][T]=1;
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	for(int i=0;i<N;++i){
		c[S][i]=1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=0;i<N;++i){
		for(int j=100;j<100+N;++j){
			if(j==(i+100)) continue;
			c[i][j]=1;
			adj[i].push_back(j);
			adj[j].push_back(i);
			d[i][j]=dist(i,j);
			d[j][i]=-dist(i,j);
		}
	}
	for(int i=0;i<N;++i){
		c[i][i+100]=1;
		adj[i].push_back(i+100);
		adj[i+100].push_back(i);
		d[i][i+100]=abs(P[i].first);
		d[i+100][i]=-abs(P[i].first);
	}
}
void solve(){
	while(1){
		int prev[VMAX];
		double dist[VMAX];
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
				if(c[now][next]>f[now][next]&&dist[next]>dist[now]+d[now][next]+1e-9){
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
	cout<<fixed;
	cout.precision(3);
	cout<<CMIN;
}
int main(){
	input();
	solve();
}
