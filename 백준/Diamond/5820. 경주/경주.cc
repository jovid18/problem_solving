#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
const int MAXN=200000;
const int MAXK=1000001;
const int INF=0x3f3f3f3f;
int N,K;
vector<pii> G[MAXN];
int min_d[MAXK];
int siz[MAXN], visited[MAXN];
vector<int> cur_dist;
int getsiz(int v, int p){
	siz[v]=1;
	for(auto [x, y]:G[v]){
		if(visited[x]||x==p) continue;
		siz[v]+=getsiz(x,v);
	}
	return siz[v];
}
int getcent(int v,int p,int cap){
	for(auto [x, y]:G[v]){
		if(visited[x]||x==p)continue;
		if(siz[x]>cap) return getcent(x,v,cap);
	}
	return v;
}
int solve(int v, int p, int dist, int depth ){
	int ret=INF;
	if(dist>K) return ret;
	ret=min(ret,min_d[K-dist]+depth);
	for(auto [x, y]:G[v]){
		if(visited[x]||x==p)  continue;
		ret=min(ret,solve(x,v,dist+y,depth+1));
	}
	return ret;
}
void update(int v,int p ,int dist, int depth){
	if(dist>K) return;
	min_d[dist]=min(min_d[dist],depth);
	cur_dist.push_back(dist);
	for(auto [x, y]:G[v]){
		if(visited[x]||x==p) continue;
		update(x,v,dist+y,depth+1);
	}
}
int go(int v){
	int cap=getsiz(v,-1)/2;
	int cen=getcent(v,-1,cap);
	visited[cen]=1;
	int ret=INF;
	while(cur_dist.size()){
		min_d[cur_dist.back()]=INF;
		cur_dist.pop_back();
	}
	min_d[0]=0;
	for(auto [x,y]:G[cen]){
		if(visited[x]) continue;
		ret=min(ret,solve(x,cen,y,1));
		update(x,cen,y,1);
	}
	for(auto [x, y]:G[cen]){
		if(visited[x]) continue;
		ret=min(ret,go(x));
	}
	return ret;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N-1;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	fill(min_d,min_d+MAXK,INF);
	int ans=go(0);
	if(ans==INF) cout<<-1;
	else cout<<ans;
}