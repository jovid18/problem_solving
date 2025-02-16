#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;
int V,E,C=0, D[MAX];
bool ap[MAX];
vector<int> G[MAX];
int apn=0;
int dfs(int p, bool root){
	D[p]=++C;
	int v=D[p];
	int child=0;
	for(auto e:G[p]){
		if(!D[e]){
			child++;
			int low=dfs(e,false);
			if(!root&&low>=D[p]) {
				ap[p]= true;
			}
			v=min(v,low);
		}else{
			v=min(v,D[e]);
		}
	}
	if(root){
		ap[p]=(child>=2);
	}
	return v;
}


int main(){
	cin>>V>>E;
	for(int i=0;i<E;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=V;++i){
		if(!D[i]) dfs(i,true);
	}
	vector<int> ans;
	for(int i=1;i<=V;++i){
		if(ap[i]){
			apn++;
			ans.push_back(i);
		}
	}
	cout<<apn<<endl;
	for(auto e: ans){
		cout<<e<<" ";
	}
}