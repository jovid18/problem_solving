#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using vi=vector<int>;
vector<vi> G,par;
vi lvl,siz;
int TC,N,Q,R,M,A,B,S,U;
int dfs(int n,int p){
	siz[n]=1;
	for(auto e:G[n]){
		if(e==p) continue;
		par[e][0]=n;
		lvl[e]=lvl[n]+1;
		siz[n]+=dfs(e,n);
	}
	return siz[n];
}
int LCA(int a,int b){
	if(a==0|| b==0) return 0;
	if(lvl[a]<lvl[b]) swap(a,b);
	if(lvl[a]!=lvl[b]){
		for(int j=M;j>=0;--j){
			if(lvl[par[a][j]]>=lvl[b]){
				a=par[a][j];
			}
		}
	}
	int res=a;
	if(a!=b){
		for(int j=M;j>=0;--j){
			if(par[a][j]!=par[b][j]){
				a=par[a][j];
				b=par[b][j];
			}
		}
		res=par[a][0];
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>TC;
	for(int tc=1;tc<=TC;++tc){
		cout<<"Case #"<<tc<<":\n";
		cin>>N>>Q>>R;
		M=ceil(log2(N));
		R--;
		G.clear();
		par.clear();
		lvl.clear();
		siz.clear();
		G.resize(N);
		lvl.assign(N,0);
		siz.assign(N,0);
		par.assign(N,vi(M+1,-1));
		for(int i=1;i<N;++i){
			cin>>A>>B;
			G[--A].push_back(--B);
			G[B].push_back(A);
		}
		dfs(0,-1);
		for(int j=1;j<M;++j){
			for(int i=0;i<N;++i){
				if(par[i][j-1]==-1) continue;
				par[i][j]=par[par[i][j-1]][j-1];
			}
		}
		for(int i=0;i<Q;++i){
			cin>>S>>U;
			U--;
			if(!S){
				R=U;
			}else{
				if(R==U){
					cout<<N<<'\n';
				}else{
					int lca=LCA(R,U);
					if(lca!=U){
						cout<<siz[U]<<'\n';
					}else{
						int ld=lvl[R]-lvl[U]-1;
						int r=R;
						for(int t=0;(1<<t)<=ld;++t){
							if(ld&(1<<t)) r=par[r][t];
						}
						cout<<N-siz[r]<<'\n';
					}
				}
			}
		}
	}
}
