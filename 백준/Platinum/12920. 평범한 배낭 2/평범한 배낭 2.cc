#include <iostream>
#include <vector>
using namespace std;

template <class T> void chmax(T& a, T b){
	if(a<b){
		a=b;
	}
} 

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	vector<int> V;
	vector<int> C;
	for(int i=0;i<N;i++){
		int v,c,k;
		cin>>v>>c>>k;
		for(int i=1;k>0;i<<=1){
			const int a= min(k,i);
			V.push_back(a*v);
			C.push_back(a*c);
			k-=a;
		}	
	}
	N=V.size();
	vector<vector<int>> dp(N+1,vector<int>(M+1,0));
	for(int i=0;i<N;++i){
		for(int j=0;j<=M;++j){
			if(j-V[i]>=0){
				chmax(dp[i+1][j],dp[i][j-V[i]]+C[i]);
			}
			chmax(dp[i+1][j],dp[i][j]);
		}
	}
	cout<<dp[N][M]<<endl;
}