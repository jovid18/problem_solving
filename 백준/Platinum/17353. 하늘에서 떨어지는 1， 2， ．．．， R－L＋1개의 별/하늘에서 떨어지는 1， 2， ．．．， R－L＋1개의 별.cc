#include <iostream>
using namespace std;
using ll=long long;
ll N,M,a,b,c;
ll A[100001];
ll B[100001];
ll T[500000];
ll L[500000];
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
	cin>>N;
	B[0]=0;
	for(int i=1;i<=N;++i){
		cin>>B[i];
	}
	for(int i=1;i<=N;++i){
		A[i]=B[i]-B[i-1];
	}
	init(1,N,1);
	cin>>M;
	for(int i=0;i<M;++i){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			update(1,N,1,b,c,1);
			if(c!=N) update(1,N,1,c+1,c+1,b-c-1);
		}else{
			cin>>b;
			cout<<query(1,N,1,1,b)<<'\n';
		}
	}
}