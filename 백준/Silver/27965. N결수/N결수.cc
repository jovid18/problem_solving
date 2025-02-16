#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
using ll=long long;
ll N,K;
ll memo[70000000];
ll  power(ll b){
	ll a=10;
	if(memo[b]!=-1){
		return memo[b];
	}
	if(b==0){
		memo[b]=1;
		return memo[b];
	}
	if(b==1){
		memo[b]=10%K;
		return memo[b];
	}
	if(b%2==0){
		ll c=power(b/2)%K;
		memo[b]=c*c%K;
		return memo[b];
	}else{
		ll c=power((b-1)/2)%K;
		memo[b]=(c*c%K)*a%K;
		return memo[b];
	}
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>K;
	if(K==1){
		cout<<0;
		return 0;
	}
	memo[0]=1;
	for(int i=1;i<70000000;++i){
		memo[i]=memo[i-1]*10%K;
	}
	ll digit=0;
	ll ans=0;
	for(ll i=N;i>=1;--i){
		ans+=i*memo[digit]%K;
		digit+=to_string(i).size();
	}
	cout<<ans%K;
}