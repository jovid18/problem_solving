#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll MOD=1e9+7;
const int MAX=100001;
int N,Q;
ll A[MAX];
ll T[4*MAX];
pll L[4*MAX];
ll init(int n, int s, int f){
	if(s==f) return T[n]=A[s];
	int m=(s+f)/2;
	return T[n]=(init(2*n,s,m)+init(2*n+1,m+1,f))%MOD;
}

void update_L(int n, int s, int f){
	auto &a1=L[n].first;
	auto &b1=L[n].second;
	if(a1==1&&b1==0) return;
	if(s!=f){
		for(int i=2*n;i<=2*n+1;++i){
			auto a2=L[i].first;
			auto b2=L[i].second;
			L[i].first=(a1*a2)%MOD;
			L[i].second=(a1*b2+b1)%MOD;
		}
	}
	T[n]=(a1*T[n]+(f-s+1)*b1)%MOD;
	a1=1;
	b1=0;
}
void update(int n,int s,int f, int l,int r,ll a, ll b){
	update_L(n,s,f);
	if(f<l||r<s) return;
	if(l<=s&&f<=r){
		L[n].first*=a; 
		L[n].first%=MOD;
		L[n].second*=a;
		L[n].second+=b;
		L[n].second%=MOD;
		update_L(n,s,f);
		return;
	}
	int m=(s+f)/2;
	update(2*n,s,m,l,r,a,b);
	update(2*n+1,m+1,f,l,r,a,b);
	T[n]=(T[2*n]+T[2*n+1])%MOD;
}
ll query(int n, int s, int f, int l, int r){
	update_L(n,s,f);
	if(r<s||f<l) return 0;
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	return (query(2*n,s,m,l,r)+query(2*n+1,m+1,f,l,r))%MOD;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>A[i];
	}
	init(1,1,N);
	for(int i=0;i<4*MAX;++i){
		L[i]={1,0};
	}
	cin>>Q;
	while(Q--){
		int op,x,y;
		ll v;
		cin>>op>>x>>y;
		if(op!=4) cin>>v;
		if(op==1){
			update(1,1,N,x,y,1,v);
		}else if(op==2){
			update(1,1,N,x,y,v,0);
		}else if(op==3){
			update(1,1,N,x,y,0,v);
		}else{
			cout<<query(1,1,N,x,y)<<'\n';
		}
	}
}