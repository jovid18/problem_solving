#include <iostream>
#include <vector>
using namespace std;
int N,M,K;
using ll=long long;
ll A[1000000]={0};
ll T[4000000]={0};
ll init(int s,int f,int n){
	if(s==f){
		return T[n]=A[s];
	}
	int m=(s+f)/2;
	return T[n]=init(s,m,2*n)+init(m+1,f,2*n+1);
}
ll sum(int s, int f, int n, int l, int r){
    if(l>f||r<s) return 0;
    if(l<=s&&f<=r) return T[n];
    int m= (s+f)/2;
    return sum(s,m,2*n,l,r) + sum(m+1,f,2*n+1,l,r);
}
void update(int s,int f,int n,int i, ll d){
	if(s==f){
		T[n]=d;
		return;
	}
	int m=(s+f)/2;
	if(s<=i and i<=m){
		update(s,m,2*n,i,d);
	}else{
		update(m+1,f,2*n+1,i,d);
	}
	T[n]=T[n*2]+T[n*2+1];
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
		}else if(a==2){
			cout<<sum(0,N-1,1,b-1,c-1)<<'\n';
		}
	}
}