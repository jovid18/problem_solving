#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int E[100001],visited[100001];
vector<vector<pair<int,int>>> P(100001,vector<pair<int,int>>(18,{0,0})),G;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second<b.second;
}
void dfs(int n){
	visited[n]=true;
	for(auto e:G[n]){
		if(visited[e.first]) continue;
		P[e.first][0]={n,e.second};
		dfs(e.first);
	}
}
int find(int n,int power){
	auto iter=lower_bound(P[n].begin(),P[n].end(),pair<int,int>{0,power},comp);
	if((*iter).second==power){
		return (*iter).first;
	}
	if(iter==P[n].begin()||n==1){
		return n;
	}
	n=(*(iter-1)).first;
	power-=(*(iter-1)).second;
	return find(n,power);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>E[i];
	}
	G.resize(N+1);
	for(int i=1;i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	dfs(1);
	P[1][0]={1,0};
	for(int i=1;i<=17;++i){
		for(int n=1;n<=N;++n){
			P[n][i].first=P[P[n][i-1].first][i-1].first;
			P[n][i].second=P[n][i-1].second+P[P[n][i-1].first][i-1].second;
		}
	}
	for(int i=1;i<=N;++i){
		cout<<find(i,E[i])<<'\n';
	}
}