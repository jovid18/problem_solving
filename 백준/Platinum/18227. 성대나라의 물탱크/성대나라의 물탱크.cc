#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int N,C,M,cnt=1;
ll T[800001];
int H[200001];
int S[200001];
int E[200001];
vector<int> adj[200001];
void dfs(int now,int par,int h){
	H[now]=h;
	S[now]=cnt++;
	for(auto e:adj[now]){
		if(e==par) continue;
		dfs(e,now,h+1);
	}
	E[now]=cnt-1;
}
ll update(int l,int r,int n,int x){
	if(x<l||r<x) return T[n];
	if(l==r) return ++T[n];
	int m=(l+r)/2;
	return T[n]=update(l,m,2*n,x)+update(m+1,r,2*n+1,x);
}
ll query(int l,int r,int n,int s,int f){
	if(f<l||r<s) return 0;
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	return query(l,r,2*n,s,m)+query(l,r,2*n+1,m+1,f);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>C;
	for(int i=0;i<N-1;++i){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin>>M;
	dfs(C,-1,1);
	while(M--){
		int a,b;
		cin>>a>>b;
		if(a&1){
			update(1,N,1,S[b]);
		}else{
			cout<<H[b]*query(S[b],E[b],1,1,N)<<'\n';
		}
	}
}