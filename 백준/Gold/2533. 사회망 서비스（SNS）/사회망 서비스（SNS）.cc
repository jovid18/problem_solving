#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> T;
vector<vector<int>> DP;
vector<bool> C;
int N;
void solve(int n){
	DP[n][1]=1;
	C[n]=true;
	for(auto e: T[n]){
		if(C[e]) continue;
		solve(e);
		DP[n][0]+=DP[e][1];
		DP[n][1]+=min(DP[e][0],DP[e][1]);
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N;
	T.resize(N+1);
	DP.assign(N+1,vector<int> (2,0));
	C.assign(N,false);
	for(int i=0;i<N-1;++i){
		int u,v;
		cin>>u>>v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	solve(1);
	cout<<min(DP[1][0],DP[1][1]);
	
 }