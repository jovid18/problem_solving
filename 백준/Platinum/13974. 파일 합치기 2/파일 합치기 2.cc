#include <iostream>
#include <vector>
using namespace std;
int T,N,INF=1e9;
int DP[5001][5001],K[5001][5001];
vector<int> P,S;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>N;
		P.assign(N+1,0);
		S.assign(N+1,0);
		for(int i=1;i<=N;++i){
			cin>>P[i];
			S[i]=P[i]+S[i-1];
		}
		for(int i=0;i<N;++i){
			DP[i][i+1]=0;
			K[i][i+1]=i+1;
		}
		for(int d=2;d<=N;++d){
			for(int i=0;i+d<=N;++i){
				int j=i+d;
				DP[i][j]=INF;
				for(int k=K[i][j-1];k<=K[i+1][j];++k){
					int nowdp=DP[i][k]+DP[k][j]+S[j]-S[i];
					if(DP[i][j]>nowdp){
						DP[i][j]=nowdp;
						K[i][j]=k;
					}
				}
			}
		}
		cout<<DP[0][N]<<'\n';
	}
}