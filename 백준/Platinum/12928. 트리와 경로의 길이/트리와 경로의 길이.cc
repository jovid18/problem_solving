#include <iostream>
using namespace std;
int N,S;
bool DP[51][100][1001]; 
int main(){
	cin>>N>>S;
	int amax=2*N-2;
	int bmax=S;
	DP[0][0][0]=true;
	for(int n=0;n<N;++n){
		for(int a=0;a<=amax;++a){
			for(int b=0;b<bmax;++b){
				if(DP[n][a][b]){
					for(int d=1;d<N;++d){
						if(a+d<100&b+d*(d-1)/2<1001)
						DP[n+1][a+d][b+d*(d-1)/2]=true;
					}
				}
			}
		}
	}
	cout<<DP[N][2*N-2][S];
}
