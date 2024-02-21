#include <iostream>
#include <vector>
using namespace std;

template <class T> void chmax(T& a, T b){
	if(a<b){
		a=b;
	}
} 
int main(){
	int N,K;
	cin>>N>>K;
	vector<int> weight;
	vector<int> value;
	for(int i=0;i<N;i++){
		int w,v;
		cin>>w>>v;
		weight.push_back(w);
		value.push_back(v);
	}
	
	vector<vector<int>> dp(N+1,vector<int>(K+1,0));
	for(int i=0;i<N;++i){
		for(int w=0;w<=K;++w){
			if(w-weight[i]>=0){
				chmax(dp[i+1][w],dp[i][w-weight[i]]+value[i]);
			}
			chmax(dp[i+1][w],dp[i][w]);
		}
	}
	
	cout<<dp[N][K]<<endl;
}