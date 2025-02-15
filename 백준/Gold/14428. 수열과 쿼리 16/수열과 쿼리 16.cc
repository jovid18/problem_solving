#include <iostream>
using namespace std;
using pii=pair<int,int>;
int N,M;
int A[100000]={0};
pii T[400000]={{0,0}};
pii init(int s,int f,int n){
	if(s==f) return T[n]={s+1,A[s]};
	int m=(s+f)/2;
	auto p1=init(s,m,2*n);
	auto p2=init(m+1,f,2*n+1);
	if(p1.second<=p2.second){
		return T[n]=p1;
	}else{
		return T[n]=p2;
	}
}
void update(int s,int f,int n,int i,int d){
	if(s==f){
		T[n]={s+1,d};
		return;
	}
	int m=(s+f)/2;
	if(i<=m){
		update(s,m,2*n,i,d);
	}else{
		update(m+1,f,2*n+1,i,d);
	}
	if(T[n*2].second<=T[2*n+1].second){
		T[n]=T[n*2];
	}else{
		T[n]=T[2*n+1];
	}
}
pii query(int s, int f,int n,int l,int r){
	if(r<s||f<l) return {0,1000000001};
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	auto p1=query(s,m,2*n,l,r);
	auto p2=query(m+1,f,2*n+1,l,r);
	if(p1.second<=p2.second){
		return p1;
	}else{
		return p2;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	init(0,N-1,1);
	cin>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			update(0,N-1,1,b-1,c);
		}else{
			cout<<query(0,N-1,1,b-1,c-1).first<<'\n';
		}
	}
}