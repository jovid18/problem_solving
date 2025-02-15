#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int N,M;
ll MOD=1000000007;
vector<pair<int,int>> G;
struct UnionFind {
	vector<int> par, siz;
	UnionFind(int n): par(n,-1),siz(n,1) {}
	int root(int x){
		if(par[x]==-1) return x;
		else return par[x]=root(par[x]);
	}
	
	bool issame(int x, int y){
		return root(x)==root(y);
	}
	
	bool unite(int x, int y){
		x=root(x);
		y=root(y);
		if(x==y) return false;
		if(siz[x]<siz[y]) swap (x,y);
		par[y]=x;
		siz[x]+=siz[y];
		return true;
	}
};
ll power(ll a,ll b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a%MOD;
	}
	if(b%2==0){
		ll c=power(a,b/2)%MOD;
		return c*c%MOD;
	}else{
		ll c=power(a,(b-1)/2)%MOD;
		return (c*c%MOD)*a%MOD;
	}
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
	cin>>N>>M;
	G.resize(M);
	for(int i=0;i<M;++i){
		cin>>G[i].first>>G[i].second;
	}
	UnionFind uf(N);
	ll ans=0;
	for(int i=M-1;i>=0;--i){
		bool A=uf.issame(0,G[i].first)&&uf.issame(N-1,G[i].second);
		bool B=uf.issame(N-1,G[i].first)&&uf.issame(0,G[i].second);
		if(A||B) ans=(ans+power(3,i))%MOD;
		else uf.unite(G[i].first,G[i].second);
	}
	cout<<ans;
}