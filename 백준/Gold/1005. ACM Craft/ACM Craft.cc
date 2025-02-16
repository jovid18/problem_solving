#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T,N,K,D;
vector<int> build;
vector<bool> seen;
vector<int> order;
vector<int> timing;
vector<vector<int>> G;

void rec(const vector<vector<int>> &G, int v){
	seen[v] = true;     
	for (auto next_v : G[v]) {
		if (seen[next_v]) continue;
		rec(G, next_v);
	}   
	order.push_back(v); 
} 

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	for(int t=0;t<T;++t){
		cin>>N>>K;
		build.resize(N);
		for(int i=0;i<N;++i){
			cin>>build[i];
		}
		G.clear();
		G.resize(N);
		for(int i=0;i<K;++i){
			int a,b;
			cin>>a>>b;
			G[a-1].push_back(b-1);
		}
		cin>>D;
		D--;
		seen.assign(N,false);
		order.clear();
		for(int v=0;v<N;++v){
			if(seen[v]) continue;
			rec(G,v);
		}
		reverse(order.begin(),order.end());
		timing.assign(N,0);
		for(int i=0;i<N;++i){
			timing[order[i]]+=build[order[i]];
			if(order[i]==D) break;
			for(auto e:G[order[i]]){
				timing[e]=max(timing[e],timing[order[i]]);
			}
		}
		cout<<timing[D]<<endl;
	}
}
