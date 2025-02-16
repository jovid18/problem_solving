#include <iostream>
#include <cstring>
using namespace std;
int N,M;
const int MOD=9901;
int dp[14*14][1<<14];
int go(int n,int s){
	if(n>=N*M){
		if(n==N*M&&s==0) return 1;
		return 0;
	}
	int &ret=dp[n][s];
	if(ret!=-1){
		return ret;
	}
	ret=0;
	if(s&1){
		ret+=go(n+1,s>>1);
	}else{
		ret+=go(n+1,(s>>1)|(1<<(M-1)));
		if(((n%M)!=M-1)&&((s&2)==0)){
			 ret+=go(n+2,s>>2);
		}
	}
	ret%=MOD;
	return ret;
} 
int main(){
	cin>>N>>M;
	memset(dp,-1,sizeof(dp));
	cout<<go(0,0);
}
