#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,K;
vector<int> C,D;

struct unionfind{
	vector<int> par;
	vector<int> siz;
	unionfind(int n): par(n,-1),siz(n,1) {
		for(int i=0;i<n;++i){
			par[i]=i;
		}
	}
	int root(int x){
		if(par[x]==x){
			return x;
		}else{
			return par[x]=root(par[x]);
		}
	}
	bool issame(int x,int y){
		return root(x)==root(y);
	}
	bool unite(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y){
			return false;
		}
		if(x>y) swap(x,y);
		par[x]=y;
		siz[y]+=siz[x];
		return true;
	}
	int size(int x){
		return siz[root(x)];
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>K;
	C.resize(M);
	D.resize(K);
	for(int i=0;i<M;++i){
		cin>>C[i];
	}
	for(int i=0;i<K;++i){
		cin>>D[i];
	}
	sort(C.begin(),C.end());
	unionfind uf(M);
	bool lastcheck=false;
	for(int i=0;i<K;++i){
		auto iter=upper_bound(C.begin(),C.end(),D[i]);
		int n=iter-C.begin();
		if(n==M){
			cout<<C[uf.root(0)]<<'\n';
			uf.unite(uf.root(0),uf.root(0)+1);
		}else{
			if(C[uf.root(n)]==M-1){
				if(lastcheck){
					cout<<C[uf.root(0)]<<'\n';
					uf.unite(uf.root(0),uf.root(0)+1);
				}else{
					cout<<C[uf.root(n)]<<'\n';
					lastcheck=true;
				}
			}else{
				cout<<C[uf.root(n)]<<'\n';
				uf.unite(uf.root(n),uf.root(n)+1);
			}
		}
	}
}