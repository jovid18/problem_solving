#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=1000000000;
using Graph= vector<vector<pair<int,int>>>;
int N,M,X;

template<class T> bool chmin(T& a, T b){
	if(a>b){
		a=b;
		return true;
	}
	else return false;
}
vector<int> tp;
vector<int> fp;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M>>X;
	Graph G(N+1);
	Graph F(N+1);
	for(int i=0;i<M;++i){
		int a,b,w;
		cin>>a>>b>>w;
		G[a].push_back({b,w});
		F[b].push_back({a,w});
	}
	vector <bool> u1(N+1,false);
	fp.assign(N+1,INF);
	fp[X]=0;
	for(int i=0;i<N;++i){
		int md=INF;
		int mv=-1;
		for(int v=1;v<=N;++v){
			if(!u1[v]&&fp[v]<md){
				md=fp[v];
				mv=v;
			}
		}
		if(mv==-1) break;
		for(auto e: G[mv]){
			chmin(fp[e.first],fp[mv]+e.second);
		}
		u1[mv]=true;
	}
	vector <bool> u2(N+1,false);
	tp.assign(N+1,INF);
	tp[X]=0;
	for(int i=0;i<N;++i){
		int md=INF;
		int mv=-1;
		for(int v=1;v<=N;++v){
			if(!u2[v]&&tp[v]<md){
				md=tp[v];
				mv=v;
			}
		}
		if(mv==-1) break;
		for(auto e: F[mv]){
			chmin(tp[e.first],tp[mv]+e.second);
		}
		u2[mv]=true;
	}
	tp[0]=0;
	fp[0]=0;
	for(int i=0;i<=N;++i){
		fp[i]+=tp[i];
	}
	cout<<*max_element(fp.begin(),fp.end());
	
}