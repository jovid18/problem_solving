#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
ll N,M;
ll A[100000];
ll T[400000];
struct about{
	ll n,q,s,f;
};
bool comp(const about &a, const about &b){
	return a.q<b.q;
}

ll init(ll s,ll f,ll n){
	if(s==f){
		return T[n]=A[s];
	}
	ll m=(s+f)/2;
	return T[n]=init(s,m,2*n)+init(m+1,f,2*n+1);
}
ll sum(ll s, ll f, ll n, ll l, ll r){
    if(l>f||r<s) return 0;
    if(l<=s&&f<=r) return T[n];
    ll m= (s+f)/2;
    return sum(s,m,2*n,l,r) + sum(m+1,f,2*n+1,l,r);
}
void update(ll s,ll f,ll n,ll i, ll d){
	if(s==f){
		T[n]=d;
		return;
	}
	ll m=(s+f)/2;
	if(i<=m){
		update(s,m,2*n,i,d);
	}else{
		update(m+1,f,2*n+1,i,d);
	}
	T[n]=T[n*2]+T[n*2+1];
}

ll qn=0;
vector<pair<ll,ll>> Q;
vector<about> P;
vector<pair<ll,ll>> ans;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(ll i=0;i<N;++i){
		cin>>A[i];
	}
	init(0,N-1,1);
	cin>>M;
	for(ll i=0;i<M;++i){
		ll a,b,c,d;
		cin>>a;
		if(a==1){
			cin>>b>>c;
			Q.push_back({b,c});
		}else{
			cin>>b>>c>>d;
			P.push_back({qn,b,c,d});
			qn++;
		}
	}
	stable_sort(P.begin(),P.end(),comp);
	ll now=0;
	int k=0;
	for(int i=0;i<=Q.size();++i){
		while(P[k].q==i&&k<P.size()){
			ans.push_back({P[k].n,sum(0,N-1,1,P[k].s-1,P[k].f-1)});
			k++;
		}
		update(0,N-1,1,Q[i].first-1,Q[i].second);
	}
	sort(ans.begin(),ans.end());
	for(auto e: ans){
		cout<<e.second<<'\n';
	}
}