#include <iostream>
#include <vector>
using namespace std;

const int INF=1000000000;
using Graph= vector<vector<pair<int,int>>>;
int TC;
int N,M,W;

template<class T> bool chmin(T& a, T b){
	if(a>b){
		a=b;
		return true;
	}
	else return false;
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>TC;
	for(int t=0;t<TC;++t){
		cin>>N>>M>>W;
		Graph G(N+1);
		for(int i=0;i<M;++i){
			int S,E,T;
			cin>>S>>E>>T;
			G[S].push_back(make_pair(E,T));
			G[E].push_back(make_pair(S,T));
		}
		for(int i=0;i<W;++i){
			int S,E,T;
			cin>>S>>E>>T;
			G[S].push_back(make_pair(E,-T));
		}
		
		bool negative_cycle=false;
		vector<int> dist(N+1,INF);
		dist[1]=0;
		for(int i=0;i<N;++i){
			bool update=false;
			for(int v=1;v<N+1;++v){
				for(auto e:G[v]){
					if(chmin(dist[e.first],dist[v]+e.second)){
						update=true;
					}
				}
			}
			if(!update) break;
			if(i==N-1&&update){
				negative_cycle=true;
			}
		}
		if(negative_cycle){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}