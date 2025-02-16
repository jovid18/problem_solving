#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=100001;
int V,E,C=0, D[MAX];
bool B[MAX];
vector<int> G[MAX];
vector<pair<int,int>> Edge;
int dfs(int i, int p){
	D[i]=++C;
	int v=D[i];
	for(auto e:G[i]){
		if(e==p) continue;
		if(!D[e]){
			int low=dfs(e,i);
			if(low>D[i]) Edge.push_back({min(e,i),max(e,i)});
			v=min(v,low);	
		}else{
			v=min(v,D[e]);
		}
	}
	return v;
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>V>>E;
	for(int i=0;i<E;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0);
	sort(Edge.begin(),Edge.end());
	cout<<Edge.size()<<'\n';
	for(auto e:Edge){
		cout<<e.first<<" "<<e.second<<'\n';
	}
}
