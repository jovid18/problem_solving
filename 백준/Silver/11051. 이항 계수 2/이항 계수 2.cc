#include <iostream>
#include <map>
using namespace std;
using ll=long long;
ll fact[1001]={1};
ll MOD=10007;
int N;
int a,b;
ll power(ll a,ll b){
	if(b==1){
		return a%MOD;
	}
	if(b%2==0){
		ll c=power(a,b/2)%MOD;
		return c*c%MOD;
	}else{
		ll c=power(a,(b-1)/2)%MOD;
		return (c*c%MOD)*a%MOD;
	}
}

ll C(int n,int r){
	ll A=fact[n];
	ll B=fact[r]*fact[n-r];
	B%=MOD;
	ll B2=power(B,MOD-2);
	ll result=A*B2;
	result%=MOD;
	return result;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll i=1;i<=1000;++i){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	cin>>a>>b;
	cout<<C(a,b)<<'\n';
}