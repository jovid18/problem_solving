#include <iostream>
#include <cstring>
using namespace std;
int loc[100001],T[800000],A[200000];
int t,n,m;
int init(int s, int f,int n){
	if(s==f) return T[n]=A[s];
	int m=(s+f)/2;
	return T[n]=init(s,m,2*n)+init(m+1,f,2*n+1);
}
int sum(int s, int f, int n, int l, int r){
	if(f<l||r<s) return 0;
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	return sum(s,m,2*n,l,r)+sum(m+1,f,2*n+1,l,r);
}
void update(int s, int f, int n, int i, int d){
	if(s==f){
		T[n]=d;
		return;
	}
	int m=(s+f)/2;
	if(i<=m){
		update(s,m,2*n,i,d);
	}else{
		update(m+1,f,2*n+1,i,d);
	}
	T[n]=T[2*n]+T[2*n+1];
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>t;
	while(t--){
		memset(loc,0,sizeof(loc));
		memset(T,0,sizeof(T));
		memset(A,0,sizeof(A));
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			loc[i]=n+1-i;
			A[i]=1;
		}
		init(1,n+m,1);
		for(int i=1;i<=m;++i){
			int a;
			cin>>a;
			cout<<sum(1,n+m,1,loc[a]+1,n+i)<<" ";
			update(1,n+m,1,loc[a],0);
			loc[a]=i+n;
			update(1,n+m,1,loc[a],1);
		}
		cout<<'\n';
	}
}