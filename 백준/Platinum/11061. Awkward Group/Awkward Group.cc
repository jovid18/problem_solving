#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
struct DSU{
	vector<int> par,sz,comb;
	DSU(int n) :par(n),sz(n),comb(n){
		for(int i=0;i<n;++i){
			par[i]=i;
			sz[i]=1;
		}
	}
	void reset(int n){
		for(int i=0;i<n;++i){
			par[i]=i;
			sz[i]=1;
			comb[i]=0;
		}
	}
	int find(int x){
		return x==par[x] ? x: (par[x]=find(par[x]));
	}
	bool unite(int x,int y){
		int u=find(x), v=find(y);
		if(u==v){ 
			comb[u]++;
			return false;
		}
		if(sz[u]>sz[v]) swap(u,v);
		sz[v]+=sz[u];
		sz[u]=0;
		par[u]=par[v];
		comb[v]+=comb[u]+1;
		return true;
	}
};
int T, n, hij;
vector<pii> V[1000001];
DSU dsu(1000);
set<pii> S;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		S.clear();
		cin>>n;
		dsu.reset(n);
		for(int i=1;i<=1000000;++i){
			V[i].clear();
		}
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				cin>>hij;
				V[hij].push_back({i,j});
			}
		}
		for(int i=1;i<=1000000;++i){
			if(V[i].empty()) continue;
			for(auto e:V[i]){
				dsu.unite(e.first,e.second);
			}
			for(int j=0;j<n;++j){
				if(dsu.find(j)==j&&1<dsu.sz[j]&&dsu.sz[j]<n){
					if(dsu.comb[j]==dsu.sz[j]*(dsu.sz[j]-1)/2) {
						S.insert({j,dsu.sz[j]});
					}
				}
			}
		}
		cout<<S.size()<<'\n';
	}
}
