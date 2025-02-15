#include <iostream>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
int N,M;
int A[1<<20];
ll F[1<<20];
ll DP[1<<20];
ll twopower(ll n){
	if(n==0) return 1;
	if(n==1) return 2;
	if(n&1){
		ll c=twopower((n-1)/2);
		return (c*c%MOD)*2%MOD;
	}else{
		ll c=twopower(n/2);
		return c*c%MOD;
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	while(N--){
		int T;
		cin>>T;
		int x=0;
		while(T--){
			int t;
			cin>>t;
			x|=1<<(t-1);
		}
		A[x]++;
	}
	for(int i=0;i<(1<<M);++i){
		F[i]=A[i];
	}
	for(int i=0;i<M;++i){
		for(int mask=0;mask<(1<<M);++mask){
			if(mask&(1<<i)){
				F[mask]+=F[mask^(1<<i)];
			}
		}
	}
	for(int mask=0;mask<(1<<M);++mask){
		DP[mask]=F[((1<<M)-1)^mask];
		DP[mask]=twopower(DP[mask]);
	}
	ll ans=0;
	for(int mask=0;mask<(1<<M);++mask){
		if(__builtin_popcount(mask)&1){
			ans+=(MOD-DP[mask])%MOD;
		}else{
			ans+=DP[mask]%MOD;
		}
	}
	cout<<ans%MOD;
}