#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int D[1000001];
int A[500000];
int B[500000];
ll T[2000000];
int N;
void update(int s,int f,int n,int i){
	if(s==f){
		T[n]=1;
		return;
	}
	int m=(s+f)/2;
	if(i<=m){
		update(s,m,2*n,i);
	}else{
		update(m+1,f,2*n+1,i);
	}
	T[n]=T[n*2]+T[n*2+1];
}
ll sum(int s, int f, int n, int l, int r){
	if(r<l) return 0;
    if(l>f||r<s) return 0;
    if(l<=s&&f<=r) return T[n];
    int m= (s+f)/2;
    return sum(s,m,2*n,l,r) + sum(m+1,f,2*n+1,l,r);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	for(int i=0;i<N;++i){
		cin>>B[i];
		D[B[i]]=i;
	}
	ll ans=0;
	for(int i=0;i<N;++i){
		ans+=sum(0,N-1,1,D[A[i]]+1,N-1);
		update(0,N-1,1,D[A[i]]);
	}
	cout<<ans;
}
