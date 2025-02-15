#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,INF=1e9;
struct score{
	int a,b,c;
	bool operator < (score x){
		return a<x.a;
	}
};
vector<score> S;
vector<int> T;
void update(int s,int f,int n,int i,int d){
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
	T[n]=min(T[2*n],T[2*n+1]);
}
int query(int s, int f,int n,int l,int r){
	if(r<s||f<l) return INF;
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	return min(query(s,m,2*n,l,r),query(m+1,f,2*n+1,l,r));
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	S.resize(N+1);
	T.assign(4*N,INF);
	for(int i=1;i<=N;++i){
		int x;
		cin>>x;
		S[x].a=i;
	}
	for(int i=1;i<=N;++i){
		int x;
		cin>>x;
		S[x].b=i;
	}
	for(int i=1;i<=N;++i){
		int x;
		cin>>x;
		S[x].c=i;
	}
	sort(S.begin()+1,S.end());
	int ans=0;
	for(int i=1;i<=N;++i){
		if(query(1,N,1,1,S[i].b)>S[i].c){
			ans++;
		}
		update(1,N,1,S[i].b,S[i].c);
	}
	cout<<ans;
}