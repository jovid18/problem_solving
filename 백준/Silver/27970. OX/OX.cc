#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string s;
using ll=long long;
const int MOD=1000000007;
ll power(int b){
	int a=2;
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	if(b%2==0){
		ll c=power(b/2)%MOD;
		return c*c%MOD;
	}else{
		ll c=power((b-1)/2)%MOD;
		return (c*c%MOD)*a%MOD;
	}
}


int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>s;
	ll ans=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='O'){
			ans+=power(i);
			ans%=MOD;
		}
	}
	cout<<ans;
}