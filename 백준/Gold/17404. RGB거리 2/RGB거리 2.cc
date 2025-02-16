#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> house;
vector<vector<int>> dp;
int answer=1000001;

int main(){
	cin>>N;
	house.assign(N,vector<int> (3,1000001));
	dp.assign(N,vector<int> (3,1000001));
	for(int i=0;i<N;++i){
		for(int k=0;k<3;++k){
			cin>>house[i][k];
		}
	}

	for(int k=0;k<3;++k){
		for(int i=0;i<3;++i){
			if(i==k){
				dp[0][i]=house[0][i];
			}else{
				dp[0][i]=1000001;
			}
		}
		for(int i=1;i<N;++i){
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+house[i][0];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+house[i][1];
			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+house[i][2];
		}
		for(int i=0;i<3;++i){
			if(i==k) continue;
			answer=min(answer,dp[N-1][i]);
		}
	}
	cout<<answer;
}