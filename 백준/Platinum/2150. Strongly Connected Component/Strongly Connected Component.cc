#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int V,E,id=0;
vector<vector<int>> G,SCC;
vector<int> P;
vector<bool> C;
stack<int> S;
int dfs(int x){
	P[x]=++id;
	S.push(x);
	int parent=P[x];
	for(auto e:G[x]){
		if(P[e]==0){
			parent=min(parent,dfs(e));
		}else if(!C[e]){
			parent=min(parent,P[e]);
		}
	}
	if (parent == P[x]) {  
		vector<int> scc;
		while (true) {
			int y = S.top(); 
			S.pop(); 
			scc.push_back(y); 
			C[y] = true; 
			if (y == x) break; 
		}
		sort(scc.begin(), scc.end()); 
		if(!scc.empty()) SCC.push_back(scc); 
	}
	return parent;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>V>>E;
	G.resize(V+1);
	P.resize(V+1);
	C.resize(V+1);
	for(int i=0;i<E;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
	}
	for(int i=1;i<=V;++i){
		if(P[i]==0) dfs(i);
	}
	cout<<SCC.size()<<endl;
	sort(SCC.begin(),SCC.end());
	for(auto e:SCC){
		for(auto f:e){
			cout<<f<<" ";
		}
		cout<<-1<<'\n';
	}
}
