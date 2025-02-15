#include <iostream>
#include <cstring>
using namespace std;
int N;
int h[51];
int dp[51][500001];
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>h[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=N;++i){
		for(int j=0;j<=500000;++j){
			if(dp[i-1][j]==-1) continue;
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			dp[i][j+h[i]]=max(dp[i][j+h[i]],dp[i-1][j]+h[i]);
			if(j>h[i]){
				dp[i][j-h[i]]=max(dp[i][j-h[i]],dp[i-1][j]);
			}else{
				dp[i][h[i]-j]=max(dp[i][h[i]-j],dp[i-1][j]+h[i]-j);
			}
		}
	}
	if(dp[N][0]<=0){
		cout<<-1;
	}else{
		cout<<dp[N][0];
	}
}