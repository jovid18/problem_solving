#include <iostream>
using namespace std;
using ll=long long;
ll N,M,K,a,b,c,d;
ll A[1000000];
ll T[5000000];
ll L[5000000];
ll init(ll s,ll f,ll n){
	if(s==f){
		return T[n]=A[s];
	}
	int m=(s+f)/2;
	return T[n]=init(s,m,2*n)+init(m+1,f,2*n+1);
}
void update_L(ll s,ll f,ll n){
	if(L[n]!=0){
		T[n]+=L[n]*(f-s+1);
		if(s!=f){
			L[2*n]+=L[n];
			L[2*n+1]+=L[n];
		}
		L[n]=0;
	}
}
void update(ll s,ll f,ll n, ll l,ll r,ll diff){
	update_L(s,f,n);
	if(f<l||r<s) return;
	if(l<=s&&f<=r){
		T[n]+=(f-s+1)*diff;
		if(s!=f){
			L[2*n]+=diff;
			L[2*n+1]+=diff;
		}
		return;
	}
	int m=(s+f)/2;
	update(s,m,2*n,l,r,diff);
	update(m+1,f,2*n+1,l,r,diff);
	T[n]=T[2*n]+T[2*n+1];
}
ll query(ll s,ll f,ll n,ll l,ll r){
	update_L(s,f,n);
	if(f<l||r<s) return 0;
	if(l<=s&&f<=r){
		return T[n];
	}
	int m=(s+f)/2;
	return query(s,m,2*n,l,r)+query(m+1,f,2*n+1,l,r);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	init(0,N-1,1);
	for(int i=0;i<M+K;++i){
		cin>>a;
		if(a==1){
			cin>>b>>c>>d;
			update(0,N-1,1,b-1,c-1,d);
		}else{
			cin>>b>>c;
			cout<<query(0,N-1,1,b-1,c-1)<<'\n';
		}
	}
}