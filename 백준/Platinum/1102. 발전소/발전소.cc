#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int N,P,M;
int C[16][16];
vector<int> DP(1<<16,1e9);
string S;
queue<pair<int,int>> Q;
int main(){
	ios_base :: sync_with_stdio(false); 	
    cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>C[i][j];
		}
	}
	string S;
	cin>>S>>P;
	for(int i=0;i<S.size();++i){
		if(S[i]=='Y') M+=1<<i;
	}
	if(__builtin_popcount(M)>=P){
		cout<<0;
		return 0;
	}
	Q.push({M,0});
	while(!Q.empty()){
		auto F=Q.front();
		Q.pop();
		if(DP[F.first]<=F.second) continue;
		DP[F.first]=F.second;
		if(__builtin_popcount(F.first)==P) continue;
		for(int i=0;i<N;++i){
			if(F.first&(1<<i)) continue;
			int jcost=1e9;
			for(int j=0;j<N;++j){
				if(F.first&(1<<j)){
					jcost=min(jcost,C[j][i]);
				}
			}
			Q.push({F.first|(1<<i),DP[F.first]+jcost});
		}
	}
	int ans=1e9;
	for(int i=0;i<(1<<N);++i){
		if(__builtin_popcount(i)==P){
			ans=min(ans,DP[i]);
		}
	}
	if(ans==1e9){
		cout<<-1;
	}else{
		cout<<ans;
	}
}