#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll N,M,a,b,c,d,cnt;
vector<ll> adj[100001];
ll S[100001];
ll E[100001];
ll T[500000];
ll L[500000];
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
void dfs(int n){
	S[n-1]=cnt++;
	for(auto e:adj[n]){
		dfs(e);
	}
	E[n-1]=cnt-1;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		int a;
		cin>>a;
		if(a!=-1){
			adj[a].push_back(i);
		}
	}
	dfs(1);
	for(int i=0;i<M;++i){
		cin>>a;
		if(a==1){
			int x;
			cin>>x>>d;
			b=S[x-1];
			c=E[x-1];
			update(0,N-1,1,b,c,d);
		}else{
			cin>>b;
			cout<<query(0,N-1,1,S[b-1],S[b-1])<<'\n';
		}
	}
}
