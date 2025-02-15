#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii= pair<int,int>;
int N,M,L,INF=1e9;
vector<vector<pii>> G;
vector<pii> R,P;
bool visited[100000];
vector<int> NT,rad;
int v1,v2,d1,d2,ans;
void dfs1(int now, int dist){
	NT.push_back(now);
	visited[now]=true;
	if(d1<dist){
		v1=now;
		d1=dist;
	}
	for(auto e: G[now]){
		if(visited[e.first]) continue;
		dfs1(e.first,dist+e.second);
	}
}
void dfs2(int now, int dist){
	visited[now]=true;
	if(d2<dist){
		v2=now;
		d2=dist;
	}
	for(auto e: G[now]){
		if(visited[e.first]) continue;
		P[e.first]={now,e.second};
		dfs2(e.first,dist+e.second);
	}
}
void findr(int i){
	NT.clear();
	d1=-1;
	d2=-1;
	dfs1(i,0);
	for(auto e: NT) visited[e]=false;
	dfs2(v1,0);
	ans=max(ans,d2);
	if(d2==0){
		rad.push_back(0);
		return;
	}
	int r=1e9;
	int nowd=0;
	int v=v2;
	while(v!=v1){
		r=min(r,max(d2-nowd,nowd));
		nowd+=P[v].second;
		v=P[v].first;
	}
	rad.push_back(r);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>L;
	G.resize(N);
	P.resize(N);
	for(int i=0;i<M;++i){
		int a,b,w;
		cin>>a>>b>>w;
		G[a].push_back({b,w});
		G[b].push_back({a,w});
	}
	for(int i=0;i<N;++i){
		if(visited[i]) continue;
		findr(i);
	}
	sort(rad.begin(),rad.end(),greater<>());
	if(rad.size()>=2) ans=max(ans,L+rad[0]+rad[1]);
	if(rad.size()>=3) ans=max(ans,2*L+rad[1]+rad[2]);
	cout<<ans;
}