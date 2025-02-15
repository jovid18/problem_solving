#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll=long long;
using pll=pair<long,long>;
const ll MAX=1e18;
vector<pll> G[5001],RG[5001];
vector<ll> tohq(5001,MAX),fromhq(5001,MAX),v;
int n,b,s,r;
ll DP[5001][5001];
int OPT[5001][5001];
ll C(ll i, ll j){
	return (j-i)*(v[j]-v[i-1]);
}
void mind(int s,vector<pll> G[5001], vector<ll> &dist){
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty()){
		ll distance=pq.top().first;
		ll now=pq.top().second;
		pq.pop();
		if(dist[now]<distance) continue;
		for(auto e: G[now]){
			ll nowd = distance+e.second;
			if(nowd<dist[e.first]){
				dist[e.first]=nowd;
				pq.push({nowd,e.first});
			}
		}
	}
	
}
void sol(int t,int s,int e,int l,int r){
	if(s>e) return;
	int m=(s+e)/2;
	ll &ret=DP[t][m];
	int &opt=OPT[t][m];
	ret=MAX;
	opt=-1;
	for(int i=l;i<=min(r,m);++i){
		ll temp=DP[t-1][i]+C(i+1,m);
		if(temp<ret){
			ret=temp;
			opt=i;
		}
	}
	sol(t,s,m-1,l,opt);
	sol(t,m+1,e,opt,r);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>b>>s>>r;
	for(int i=0;i<r;++i){
		ll a,b,w;
		cin>>a>>b>>w;
		G[a].push_back({b,w});
		RG[b].push_back({a,w});
	}
	mind(b+1,G,fromhq);
	mind(b+1,RG,tohq);
	v.push_back({0});
	for(int i=1;i<=b;++i){
		v.push_back(fromhq[i]+tohq[i]);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=b;++i){
		v[i]+=v[i-1];
	}
	for(int i=1;i<=b;++i){
		DP[1][i]=C(1,i);
		OPT[1][i]=1;
	}
	for(int t=2;t<=s;++t){
		sol(t,1,b,1,b);
	}
	cout<<DP[s][b];
}