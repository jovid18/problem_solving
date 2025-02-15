#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long ;
ll DP[100000];
ll down[100000];
ll up[100000];
ll N,C;
vector<ll> h;
const ll INF=1e12;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>C;
	h.resize(N);
	for(int i=0;i<N;++i){
		cin>>h[i];
	}
	for(int i=0;i<N;){
		for(int j=1;j<=100;++j){
			if(j<h[i]){
				DP[j]=INF;
			}else if(i==0){
				DP[j]=(j-h[i])*(j-h[i]);
			}else{
				DP[j]=(j-h[i])*(j-h[i])+min(down[j]-C*j,up[j]+C*j);
			}
		}
		++i;
		for(int j=1;j<=100;++j){
			if(j==1){
				down[101-j]=DP[101-j]+C*(101-j);
				up[j]=DP[j]-C;
			}else{
				down[101-j]=min(DP[101-j]+C*(101-j),down[102-j]);
				up[j]=min(DP[j]-C*j,up[j-1]);
			}
		}
	}
	ll ans=INF;
	for(int i=1;i<=100;++i){
		ans=min(ans,DP[i]);
	}
	cout<<ans;
}