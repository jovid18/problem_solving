#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> DP(1001,vector<int>(1001,-1));
string S;
int MOD=10007;
int dp(int s, int e){
	if(s>e){
		return 0;
	}
	if(DP[s][e]!=-1){
		return DP[s][e];
	}
	if(s==e){
		DP[s][e]=1;
	}else if(S[s]==S[e]){
		DP[s][e]=(1+dp(s+1,e)+dp(s,e-1))%MOD;
	}else{
		DP[s][e]=(dp(s+1,e)+dp(s,e-1)-dp(s+1,e-1)+MOD)%MOD;
	}
	return DP[s][e];
}
int main(){
	cin>>S;
	cout<<dp(0,S.size()-1)<<endl;
}