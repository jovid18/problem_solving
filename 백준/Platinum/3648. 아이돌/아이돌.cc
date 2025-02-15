#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX=1000;
int N,M,id,scn;
vector<vector<int>> G(2*MAX);
vector<int> P(2*MAX),SCC(2*MAX);
vector<bool> C(2*MAX);
stack<int> S;
int OP(int n){
	return n%2?n-1:n+1;
}
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
	if(parent==P[x]){
		while(true){
			int y=S.top();
			S.pop();
			C[y]=true;
			SCC[y]=scn;
			if(y==x) break;
		}
		scn++;
	}
	return parent;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(cin>>N>>M){
		G.clear();
		G.resize(2*MAX);
		P.assign(2*MAX,0);
		SCC.assign(2*MAX,0);
		C.assign(2*MAX,false);
		while(!S.empty()) S.pop();
		id=0;
		scn=0;
		for(int i=0;i<M;++i){
			int a,b;
			cin>>a>>b;
			a=(a>0?2*a-1:-2*(a+1));
			b=(b>0?2*b-1:-2*(b+1));
			G[OP(a)].push_back(b);
			G[OP(b)].push_back(a);
		}
		G[OP(1)].push_back(1);
		for(int i=0;i<2*N;++i){
			if(!C[i]) dfs(i);
		}
		
		bool pass=false;
		for(int i=0;i<N;++i){
			if(SCC[2*i]==SCC[2*i+1]){
				pass=true;
				continue;
			}
		}
		cout<<(pass ? "no" : "yes")<<'\n';
	}
}