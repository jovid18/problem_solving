#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
long long N,M;
long long INF=1e63;
vector<int> P;
long long dp[301][301][2];
long long find(int l,int r,int s,int k){
	if(k==0) return 0;
	if(dp[l][r][s]!=-1) return dp[l][r][s];
	long long left=INF,right=INF;
	if(l!=0){
		if(s){
			left=min(left,find(l-1,r,0,k-1)+k*(P[r]-P[l-1]));
		}else{
			left=min(left,find(l-1,r,0,k-1)+k*(P[l]-P[l-1]));
		}
	}
	if(r!=N){
		if(s){
			right=min(right,find(l,r+1,1,k-1)+k*(P[r+1]-P[r]));
		}else{
			right=min(right,find(l,r+1,1,k-1)+k*(P[r+1]-P[l]));
		}
	}
	dp[l][r][s]=min(left,right);
	return dp[l][r][s];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	P.resize(N);
	for(int i=0;i<N;++i){
		cin>>P[i];
	}
	P.push_back(0);
	sort(P.begin(),P.end());
	int index=lower_bound(P.begin(),P.end(),0)-P.begin();
	long long ans=0;
	for(long long i=1;i<=N;++i){
		memset(dp,-1,sizeof(dp));
		ans=max(ans,M*i-find(index,index,0,i));
	}
	cout<<ans;
}