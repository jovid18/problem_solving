#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int N,D;
ll ans;
vector<ll> V,T,P;
ll C(ll i,ll j){
	if(i>j) return -1;
	return (j-i)*T[j]+V[i];
}
void sol(int s,int e,int searchl,int searchr){
	if(s>e) return;
	int m=(s+e)/2;
	int k=max(searchl,m-D);
	for(int i=k;i<=min(searchr,m);++i){
		if(C(k,m)<C(i,m)) k=i;
	}
	ans=max(ans,C(k,m));
	sol(s,m-1,searchl,k);
	sol(m+1,e,k,searchr);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>D;
	V.resize(N+1);
	T.resize(N+1);
	P.resize(N+1);
	P[0]=1;
	for(int i=1;i<=N;++i) cin>>T[i];
	for(int i=1;i<=N;++i) cin>>V[i];
	sol(1,N,1,N);
	cout<<ans;
}