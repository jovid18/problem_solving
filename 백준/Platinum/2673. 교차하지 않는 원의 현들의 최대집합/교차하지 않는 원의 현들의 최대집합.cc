#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> L;
int N;
vector<vector<int>> DP(102,vector<int>(102,-1));
int find(int s,int f){
	if(DP[s][f]!=-1) return DP[s][f];
	DP[s][f]=0;
	for(int i=0;i<N;++i){
		if(s>L[i].first||L[i].second>f) continue;
		DP[s][f]=max(DP[s][f],find(s,L[i].first-1)+find(L[i].first+1,L[i].second-1)+find(L[i].second+1,f)+1);
	}
	return DP[s][f];
}
int main(){
	cin>>N;
	L.resize(N);
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		L[i]={a,b};
	}
	cout<<find(1,100);
}