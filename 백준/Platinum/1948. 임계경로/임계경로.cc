#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
	int v,w;
};
vector<vector<Edge>> G1,G2;
vector<int> maxtime,indegree,visited1,visited2;
queue<int> Q1,Q2;
int n,m,s,f,run;
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n>>m;
	G1.resize(n+1);
	G2.resize(n+1);
	indegree.resize(n+1);
	maxtime.resize(n+1);
	visited1.resize(n+1);
	visited2.resize(n+1);
	for(int i=0;i<m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		G1[a].push_back({b,c});
		G2[b].push_back({a,c});
		indegree[b]++;
	}
	cin>>s>>f;
	Q1.push(s);
	while(!Q1.empty()){
		auto now=Q1.front();
		Q1.pop();
		visited1[now]=true;
		for(auto e:G1[now]){
			if(visited1[e.v]) continue;
			maxtime[e.v]=max(maxtime[now]+e.w,maxtime[e.v]);
			indegree[e.v]--;
			if(indegree[e.v]==0){
				Q1.push(e.v);
			}
		}
	}
	Q2.push(f);
	visited2[f]=true;
	while(!Q2.empty()){
		auto now=Q2.front();
		Q2.pop();
		for(auto e:G2[now]){
			if(maxtime[now]!=maxtime[e.v]+e.w) continue; 
			run++;
			if(visited2[e.v]) continue;
			Q2.push(e.v);
			visited2[e.v]=true;
		}
	}
	cout<<maxtime[f]<<endl<<run<<endl;
}

