#include <iostream>
using namespace std;
int C[53][53]={0};
int mod=10007;
int N;
int main() {
	cin>>N;
	for(int i=0;i<=52;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=mod;
		}
	}
	int count=0;
	for(int i=1;i*4<=N;++i){
		if(i%2==1){
			count+=C[13][i]*C[52-4*i][N-4*i];
			count%=mod;
		}else{
			int X=C[13][i]*C[52-4*i][N-4*i]%10007;
			count-=X-mod;
			count%=mod;
		}
	}
	cout<<count;
}
