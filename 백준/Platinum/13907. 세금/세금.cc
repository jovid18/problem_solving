#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll=long long;
const ll INF=1LL<<60;
ll sum=0;
int N,M,K,S,D,a,b,w;
vector<vector<ll>> DP;
vector<vector<pair<int,int>>> G;
struct Edge{
	long long d;
	int edge;
	int n;
};
struct cmp {
  bool operator()(Edge a, Edge b) {
  	return a.d>b.d;
  }
}; 
ll findmin(int f){
	ll ans=INF;
	for(ll i=0;i<N;++i){
		ans=min(ans,DP[f][i]+sum*i);
	}
	return ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>K>>S>>D;
	G.resize(N+1);
	for(int i=0;i<M;++i){
		cin>>a>>b>>w;
		G[a].push_back({w,b});
		G[b].push_back({w,a});
	}
	DP.assign(N+1,vector<ll>(N,INF));
	priority_queue<Edge,vector<Edge>,cmp> pq;
	DP[S][0]=0;
	pq.push({DP[S][0],S,0});
	while(!pq.empty()){
		ll d=pq.top().d;
		int edge=pq.top().edge;
		int n=pq.top().n;
		pq.pop();
		if(DP[edge][n]<d) continue;
		for(auto e:G[edge]){
			ll x=DP[edge][n]+e.first;
			if(DP[e.second][n+1]>x){
				bool pass=false;
				for(int j=0;j<n+1;++j){
					if(DP[e.second][j]<x){
						pass=true;
						continue;
					}
				}
				if(pass) continue;
				DP[e.second][n+1]=x;
				pq.push({x,e.second,n+1});
			}
		}
	}
	cout<<findmin(D)<<'\n';
	for(int i=0;i<K;++i){
		ll s;
		cin>>s;
		sum+=s;
		cout<<findmin(D)<<'\n';
	}
}
