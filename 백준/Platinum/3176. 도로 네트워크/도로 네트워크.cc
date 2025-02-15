#include <iostream>
#include <vector>
using namespace std;
struct Edge{
	int PRT;
	int MIN;
	int MAX;
};
int N,K;
int visited[100001],level[100001];
vector<vector<Edge>> P(100001,vector<Edge>(18,{0,100000000,0}));
vector<vector<pair<int,int>>> G;
vector<pair<int,int>> Q;
void dfs(int n,int lvl){
	visited[n]=true;
	level[n]=lvl;
	for(auto e:G[n]){
		if(visited[e.first]) continue;
		P[e.first][0]={n,e.second,e.second};
		dfs(e.first,lvl+1);
	}
}
void LCA(int a,int b){
	if(level[a]<level[b]) swap(a,b);
	if(b==1){
		cout<<P[a][17].MIN<<" "<<P[a][17].MAX<<'\n';
		return ;
	}
	int abmin=1e9,abmax=0;
	if(level[a]!=level[b]){
		for(int i=17;i>=0;--i){
			if(level[P[a][i].PRT]>=level[b]){
				abmin=min(abmin,P[a][i].MIN);
				abmax=max(abmax,P[a][i].MAX);
				a=P[a][i].PRT;
			}
		}
	}
	if(a!=b){
		for(int i=18;i>=0;--i){
			if(P[a][i].PRT!=P[b][i].PRT){
				abmin=min(abmin,P[a][i].MIN);
				abmax=max(abmax,P[a][i].MAX);
				abmin=min(abmin,P[b][i].MIN);
				abmax=max(abmax,P[b][i].MAX);
				a=P[a][i].PRT;
				b=P[b][i].PRT;
			}
		}
		abmin=min(abmin,P[a][0].MIN);
		abmax=max(abmax,P[a][0].MAX);
		abmin=min(abmin,P[b][0].MIN);
		abmax=max(abmax,P[b][0].MAX);
	}
	cout<<abmin<<" "<<abmax<<'\n';
}
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N;
	G.resize(N+1);
	for(int i=1;i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	cin>>K;
	Q.resize(K);
	for(int i=0;i<K;++i){
		cin>>Q[i].first>>Q[i].second;
	}
	dfs(1,0);
	P[1][0].PRT=1;
	for(int i=1;i<=17;++i){
		for(int n=1;n<=N;++n){
			P[n][i].PRT=P[P[n][i-1].PRT][i-1].PRT;
			P[n][i].MIN=min(P[n][i-1].MIN,P[P[n][i-1].PRT][i-1].MIN);
			P[n][i].MAX=max(P[n][i-1].MAX,P[P[n][i-1].PRT][i-1].MAX);
		}
	}
	for(int i=0;i<K;++i){
		LCA(Q[i].first,Q[i].second);
	}
}