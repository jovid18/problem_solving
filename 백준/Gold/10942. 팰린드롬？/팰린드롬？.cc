#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> num;
int dp[2000][2000]={0};

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	num.resize(N);
	for(int i=0;i<N;++i){
		cin>>num[i];
	}
	for(int i=0;i<N;++i){
		dp[i][i]=1;
	}
	for(int i=0;i<N-1;++i){
		int j=i+1;
		if(num[j]==num[i]){
			dp[i][j]=1;
		}
	}
	
	for(int n=2;n<=N-1;++n){
		for(int i=0;i<N-n;++i){
			int j=i+n;
			if(dp[i+1][j-1]==1&&num[i]==num[j]){
				dp[i][j]=1;
			}
		}
	}
	cin>>M;
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		cout<<dp[a-1][b-1]<<'\n';
	}
}