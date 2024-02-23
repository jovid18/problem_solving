#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N,M,H;
vector<int> adj[100001];
vector<vector<int>> par;
vector<int> Q(3),P(3),lvl;
void dfs(int n, int p){
	for(auto e:adj[n]){
		if(e==p) continue;
		par[e][0]=n;
		lvl[e]=lvl[n]+1;
		dfs(e,n);
	}
}
int LCA(int a,int b){
	if(a==1|| b==1) return 1;
	if(lvl[a]<lvl[b]) swap(a,b);
	if(lvl[a]!=lvl[b]){
		for(int j=H;j>=0;--j){
			if(lvl[par[a][j]]>=lvl[b]){
				a=par[a][j];
			}
		}
	}
	int res=a;
	if(a!=b){
		for(int j=H;j>=0;--j){
			if(par[a][j]!=par[b][j]){
				a=par[a][j];
				b=par[b][j];
			}
		}
		res=par[a][0];
	}
	return res;
}
int middle(int a, int b){
	if(a==b) return a;
	if(lvl[a]<lvl[b]) swap(a,b);
	int lca=LCA(a,b);
	if(b==lca){
		int d=lvl[a]-lvl[b];
		if(d&1){
			return -1;
		}else{
			d/=2;
			for(int i=H;i>=0;--i){
				if(d<pow(2,i)) continue;
				a=par[a][i];
				d-=pow(2,i);
				if(!d) break;
			}
			return a;
		}
	}else{
		if(lvl[a]==lvl[b]) return lca;
		int d1=lvl[a]-lvl[lca];
		int d2=lvl[b]-lvl[lca];
		int d=d1+d2;
		if(d&1){
			return -1;
		}else{
			d/=2;
			for(int i=H;i>=0;--i){
				if(d<pow(2,i)) continue;
				a=par[a][i];
				d-=pow(2,i);
				if(!d) break;
			}
			return a;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<N;++i){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	H=ceil(log2(N));
	lvl.assign(N+1,0);
	par.assign(N+1,vector<int>(H+1,-1));
	dfs(1,-1);
	for(int j=1;j<=H;++j){
		for(int i=1;i<=N;++i){
			if(par[i][j-1]==-1) continue;
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	cin>>M;
	while(M--){
		Q.resize(3);
		cin>>Q[0]>>Q[1]>>Q[2];
		sort(Q.begin(),Q.end());
		Q.erase(unique(Q.begin(),Q.end()),Q.end());
		if(Q.size()==1){
			cout<<Q[0]<<'\n';
		}else if(Q.size()==2){
			cout<<middle(Q[0],Q[1])<<'\n';
		}else{
			P[0]=middle(Q[0],Q[1]);
			P[1]=middle(Q[1],Q[2]);
			P[2]=middle(Q[0],Q[2]);
			sort(P.begin(),P.end());
			if(P[0]==-1) cout<<-1<<'\n';
			else if(P[0]==P[1]) cout<<P[0]<<'\n';
			else if(P[1]==P[2]) cout<<P[1]<<'\n';
            else cout<<-1<<'\n';
		}
	}
}