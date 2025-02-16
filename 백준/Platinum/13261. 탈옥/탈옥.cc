#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int L,G;
vector<ll> S;
ll DP[801][8001],OPT[801][8001];
ll C(ll i,ll j){
	return (j-i+1)*(S[j]-S[i-1]);
}
void sol(int t,int s,int e,int l,int r){
	if(s>e) return;
	int m=(s+e)/2;
	ll &ret=DP[t][m];
	ll &opt=OPT[t][m];
	ret=1e18;
	opt=-1;
	for(int i=l;i<=min(r,m);++i){
		ll temp=DP[t-1][i]+C(i+1,m);
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
	cin>>L>>G;
	S.resize(L+1);
	for(int i=1;i<=L;++i){
		cin>>S[i];
		S[i]+=S[i-1];
	}
	for(int i=1;i<=L;++i){
		DP[1][i]=C(1,i);
		OPT[1][i]=0;
	}
	for(int t=2;t<=G;++t){
		sol(t,1,L,1,L);
	}
	cout<<DP[G][L];
}