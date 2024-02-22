#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct unionfind{
	vector<int> par;
	vector<int> siz;
	unionfind(int n): par(n,-1),siz(n,1) {}
	int root(int x){
		if(par[x]==-1){
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
		if(siz[x]<siz[y]) swap(x,y);
		par[y]=x;
		siz[x]+=siz[y];
		return true;
	}
	int size(int x){
		return siz[root(x)];
	}
};


int main(){
	int people,party;
	cin>>people>>party;
	vector<int> truemem;
	int truenum;
	cin>>truenum;
	truemem.resize(truenum);
	for(int i=0;i<truenum;++i){
		cin>>truemem[i];
	}
	vector<vector<int>> partymem(party);
	for(int i=0;i<party;++i){
		int a;
		cin>>a;
		partymem[i].resize(a);
		for(int j=0;j<a;++j){
			cin>>partymem[i][j];
		}
	}
	unionfind uf(people+1);
	for(int i=0;i<truenum-1;++i){
		uf.unite(truemem[i],truemem[i+1]);
	}
	for(int i=0;i<party;++i){
		for(int j=0;j<partymem[i].size()-1;++j){
			uf.unite(partymem[i][j],partymem[i][j+1]);
		}
	}

	int truefirst;
	if(truenum==0){
		truefirst=0;
	}else{
		truefirst=truemem[0];
	}
	int count=0;
	for(int i=0;i<party;++i){
		if(!uf.issame(truefirst,partymem[i][0])){
			count++;
		}
	}
	cout<<count;
	
	
}
