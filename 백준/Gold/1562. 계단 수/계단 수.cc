#include <iostream>
using namespace std;

long long DP[101][10][1<<10]={0};
const long long MOD= 1000000000;
int N;


int main(){
	cin>>N;
	for(int i=1;i<=9;++i){
		DP[1][i][1<<i]=1;
	}
	for(int i=2;i<=100;++i){
		for(int n=0;n<=9;++n){
			for(int k=0;k<(1<<10);++k){
				int kn=k|(1<<n);
				if(n==0){
					DP[i][n][kn]+=DP[i-1][n+1][k];
					DP[i][n][kn]%=MOD;
				}else if(n==9){
					DP[i][n][kn]+=DP[i-1][n-1][k];
					DP[i][n][kn]%=MOD;
				}else{
					DP[i][n][kn]+=(DP[i-1][n-1][k]+DP[i-1][n+1][k]);
					DP[i][n][kn]%=MOD;
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<10;++i){
		ans+=DP[N][i][1023];
	}
	cout<<ans%MOD;
	
}