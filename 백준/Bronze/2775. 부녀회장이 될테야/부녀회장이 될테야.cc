#include <iostream>
#include <string>
using namespace std;
int DP[15][15];
int T,k,n;
int main(){
	for(int i=1;i<15;++i){
		DP[0][i]=i;
	}
	for(int i=1;i<=14;++i){
		for(int j=1;j<=14;++j){
			int &ret=DP[i][j];
			for(int k=1;k<=j;++k){
				ret+=DP[i-1][k];
			}
		}
	}
	cin>>T;
	while(T--){
		cin>>k>>n;
		cout<<DP[k][n]<<'\n';
	}
}