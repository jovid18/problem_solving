#include <iostream>
using namespace std;
using ll=long long;
ll A[1000000]={0};
ll T[4000000]={0};
int N,M,K;
ll mod=1000000007;
ll init(int s, int f,int n){
	if(s==f) return T[n]=A[s]%mod;
	int m=(s+f)/2;
	return T[n]=(init(s,m,2*n)*init(m+1,f,2*n+1))%mod;
}
ll pro(int s, int f, int n, int l,int r){
	if(f<l||r<s){
		return 1;
	}
	if(l<=s&&f<=r){
		return T[n]%mod;
	}
	int m=(s+f)/2;
	return (pro(s,m,2*n,l,r)*pro(m+1,f,2*n+1,l,r))%mod;
}
void update(int s,int f,int n, int i,ll v){
	if(s==f) {
		T[n]=v%mod;
		return;
	}
	int m=(s+f)/2;
	if(i<=m){
		update(s,m,2*n,i,v);
	}else{
		update(m+1,f,2*n+1,i,v);
	}
	T[n]=(T[2*n]*T[2*n+1])%mod;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	init(0,N-1,1);
	for(int i=0;i<M+K;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			update(0,N-1,1,b-1,c);
		}else{
			cout<<pro(0,N-1,1,b-1,c-1)<<'\n';
		}
	}	
}