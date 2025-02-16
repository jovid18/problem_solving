#include <iostream>
#include <vector>
using namespace std;
int N;
using ll=long long;
const int MAX=100001;
const ll MOD=1e9+7;
ll A[MAX],T[12][4*MAX];
ll sum(int nth,int n,int s, int f, int l, int r){
	if(r<l) return 0;
    if(l>f||r<s) return 0;
    if(l<=s&&f<=r) return T[nth][n]%=MOD;
    int m= (s+f)/2;
    return (sum(nth,2*n,s,m,l,r)+sum(nth,2*n+1,m+1,f,l,r))%MOD;
}
void update(int nth,int n,int s,int f,int idx, ll diff){
	if(idx<s||f<idx) return;
	T[nth][n]+=diff;
	T[nth][n]%=MOD;
	if(s==f) return;
	int m=(s+f)/2;
	update(nth,2*n,s,m,idx,diff);
	update(nth,2*n+1,m+1,f,idx,diff);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i];
		update(1,1,1,N,A[i],1);
		for(int j=2;j<=11;++j){
			ll diff=sum(j-1,1,1,N,1,A[i]-1);
			if(diff==0) continue;
			update(j,1,1,N,A[i],diff);
		}
	}
	cout<<sum(11,1,1,N,3,N);
}