#include <iostream>
using namespace std;
const int MAX=1000001;
using ll=long long;
ll A[MAX],T[4*MAX],DP[MAX];
int N,D;
ll init(int n, int s, int f){
	if(s==f) return T[n]=A[s];
	int m=(s+f)/2;
	return T[n]=max(init(2*n,s,m),init(2*n+1,m+1,f));
}
ll query(int n, int s, int f, int l, int r){
	if(f<l||r<s) return -1e9-1;
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	return max(query(2*n,s,m,l,r),query(2*n+1,m+1,f,l,r));
}
void update(int n,int s,int f,int i, ll d){
	if(s==f){
		T[n]=d;
		return;
	}
	int m=(s+f)/2;
	if(i<=m) update(2*n,s,m,i,d);
	else update(2*n+1,m+1,f,i,d);
	T[n]=max(T[n*2],T[n*2+1]);
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>D;
	for(int i=1;i<=N;++i) cin>>A[i];
	init(1,1,N);
	for(int i=1;i<=N;++i){
		DP[i]=A[i];
	}
	for(int i=2;i<=N;++i){
		int j=max(1,i-D);
		ll diff=query(1,1,N,j,i-1);
		if(diff<0) continue;
		DP[i]+=diff;
		update(1,1,N,i,DP[i]);
	}
	ll ans=-1e9-1;
	for(int i=1;i<=N;++i){
		ans=max(ans,DP[i]);
	}
	cout<<ans;
}