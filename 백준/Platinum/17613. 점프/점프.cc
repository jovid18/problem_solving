#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int T;
ll DP[31];
vector<ll> sep;
ll sol(ll s, ll e){
	if(s==0){
		if(e==0) return 0;
		auto eidx=lower_bound(sep.begin(),sep.end(),e)-sep.begin();
		if(sep[eidx-1]==e) return eidx;
	}
	ll idx=upper_bound(sep.begin(),sep.end(),e)-sep.begin();
	ll m2=(1<<idx)-1;
	ll m1=(1<<(idx-1))-1;
	if(m2<=s){
		return idx+sol(s-m2,e-m2);
	}else if(m1<=s){
		return max(sol(s,m2-1),idx+sol(0,e-m2));
	}else{
		ll ans=max(sol(s,m1-1),idx+sol(0,e-m2));
		ans=max(ans,DP[idx-1]);
		return ans;
	}
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll i=1;i<=30;++i){
		sep.push_back((1<<i)-1);
		DP[i]=1+i*(i+1)/2;
	}
	cin>>T;
	while(T--){
		ll a,b;
		cin>>a>>b;
		cout<<sol(a,b)<<'\n';
	}
}