#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
		par[y]=x;
		siz[x]+=siz[y];
		return true;
	}
	int size(int x){
		return siz[root(x)];
	}
};

int G,P;
int gate[100000]={0};

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>G>>P;
	unionfind uf(G+1);
	for(int i=0;i<P;++i){
		cin>>gate[i];
	}
	bool ok=false;
	for(int i=0;i<P;++i){
		if(uf.par[gate[i]]==gate[i]){
			uf.unite(gate[i]-1,gate[i]);
		}else{
			int first=uf.root(gate[i]);
			if(first==0){
				cout<<i<<endl;
				ok=true;
				break;
			}
			uf.unite(first-1,first);
		}
	}

	if(!ok){
		cout<<P;
	}
}