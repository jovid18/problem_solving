#include <iostream>
#include <string>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
ll C,N,O;
string cmd;
pll T[20000000];
ll L[20000000];
void update_L(ll s,ll f,ll n){
	if(L[n]!=0){
		T[n].first+=L[n];
		T[n].second+=L[n];
		if(s!=f){
			L[2*n]+=L[n];
			L[2*n+1]+=L[n];
		}
		L[n]=0;
	}
}
void update(ll s,ll f,ll n, ll l,ll r,ll diff){
	if(diff==0) return;
	update_L(s,f,n);
	if(f<l||r<s) return;
	if(l<=s&&f<=r){
		L[n]+=diff;
		update_L(s,f,n);
		return;
	}
	int m=(s+f)/2;
	update(s,m,2*n,l,r,diff);
	update(m+1,f,2*n+1,l,r,diff);
	T[n].first=min(T[2*n].first,T[2*n+1].first);
	T[n].second=max(T[2*n].second,T[2*n+1].second);
}
pll query(int s,int f,int n,int l,int r){
	update_L(s,f,n);
	if(f<l||r<s) return{1000000001,0};
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	auto p1=query(s,m,2*n,l,r);
	auto p2=query(m+1,f,2*n+1,l,r);
	return {min(p1.first,p2.first),max(p1.second,p2.second)};
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin>>C>>N>>O;
	for(int i=0;i<O;++i){
		cin>>cmd;
		if(cmd=="change"){
			ll X,S;
			cin>>X>>S;
			auto p=query(0,C-1,1,X,X);
			if(S>0){
				cout<<min(S,N-p.second)<<'\n';
				update(0,C-1,1,X,X,min(S,N-p.second));
			}else{
				cout<<max(S,-p.first)<<'\n';
				update(0,C-1,1,X,X,max(S,-p.first));
			}
		}else if(cmd=="groupchange"){
			ll A,B,S;
			cin>>A>>B>>S;
			auto p=query(0,C-1,1,A,B);
			if(S>0){
				cout<<min(S,N-p.second)<<'\n';
				update(0,C-1,1,A,B,min(S,N-p.second));
			}else{
				cout<<max(S,-p.first)<<'\n';
				update(0,C-1,1,A,B,max(S,-p.first));
			}
		}else{
			ll X;
			cin>>X;
			cout<<query(0,C-1,1,X,X).first<<'\n';
		}
	}
}