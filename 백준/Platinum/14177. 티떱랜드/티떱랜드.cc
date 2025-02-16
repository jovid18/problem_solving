#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int N,K;
int U[4001][4001];
ll DP[4001][4001], C[4001][4001];
int OPT[4001][4001];
void sol(int t,int s,int e,int l,int r){
	if(s>e) return;
	int m=(s+e)/2;
	ll &ret=DP[t][m];
	int &opt=OPT[t][m];
	ret=1e9;
	opt=-1;
	for(int i=l;i<=min(r,m);++i){
		ll temp=DP[t-1][i]+C[i+1][m];
		if(temp<ret){
			ret=temp;
			opt=i;
		}
	}
	sol(t,s,m-1,l,opt);
	sol(t,m+1,e,opt,r);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>U[i][j];
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			U[i][j]+=U[i][j-1];
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			U[j][i]+=U[j-1][i];
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;++j){
			C[i][j]=U[i-1][i-1]+U[j][j]-U[i-1][j]-U[j][i-1];
		}
	}
	for(int i=1;i<=N;++i){
		DP[1][i]=C[1][i];
		OPT[1][i]=1;
	}
	for(int t=2;t<=K;++t){
		sol(t,1,N,1,N);
	}
	cout<<DP[K][N]/2;
}