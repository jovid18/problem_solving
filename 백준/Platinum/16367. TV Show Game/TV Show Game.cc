#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX=5000;
int N,M,id,scn;
vector<vector<int>> G(2*MAX);
vector<int> P(2*MAX),SCC(2*MAX),ANS(MAX,-1);
vector<bool> C(2*MAX);
vector<pair<int,int>> p;
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
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		char d,e,f;
		cin>>a>>d>>b>>e>>c>>f;
		a=(d=='R'?2*a-1:2*(a-1));
		b=(e=='R'?2*b-1:2*(b-1));
		c=(f=='R'?2*c-1:2*(c-1));
		G[OP(a)].push_back(b);
		G[OP(b)].push_back(a);
		G[OP(c)].push_back(b);
		G[OP(b)].push_back(c);
		G[OP(a)].push_back(c);
		G[OP(c)].push_back(a);
	}
	for(int i=0;i<2*N;++i){
		if(!C[i]) dfs(i);
	}
	for(int i=0;i<N;++i){
		if(SCC[2*i]==SCC[2*i+1]){
			cout<<-1;
			return 0;
		}
	}
	p.resize(2*N);
	for(int i=0;i<2*N;++i){
		p[i]={SCC[i],i};
	}
	sort(p.begin(),p.end());
	for(int i=2*N-1;i>=0;--i){
		int n=p[i].second;
		if(ANS[n/2]==-1) ANS[n/2]=!(n%2);
	}
	for(int i=0;i<N;++i){
		cout<<(ANS[i]==0?'B':'R');
	}
}