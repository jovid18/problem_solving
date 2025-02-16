#include <iostream>
using namespace std;
int N,last;
const int MAX=987654321;
int cost[16][16]={0};
int dp[16][1<<16]={0};
int search(int now, int visited){
	if(visited==last){
		if(cost[now][0]>0){
			return cost[now][0];
		}
		return MAX;
	}
	if(dp[now][visited]!=0){
		return dp[now][visited];
	}
	dp[now][visited]=MAX;
	for(int i=0;i<N;++i){
		if(cost[now][i]==0) continue;
		if(visited&(1<<i)) continue;
		int temp=search(i,visited|1<<i);
		dp[now][visited]=min(dp[now][visited],cost[now][i]+temp);
	}
	return dp[now][visited];
	
}
int main(){
	cin>>N;
	last=(1<<N)-1;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>cost[i][j];
		}
	}
	cout<<search(0,1);
}