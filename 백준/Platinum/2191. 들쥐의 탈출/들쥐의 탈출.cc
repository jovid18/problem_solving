#include <iostream>
#include <vector>
using namespace std;
int N,M,S,V;
vector<pair<double,double>> MO,TU;
vector<int> A,B;
vector<bool> visited;
vector<vector<int>> edge;
bool dfs(int a){
	visited[a]=true;
	for(auto b:edge[a]){
		if(B[b] == -1 || (!visited[B[b]] && dfs(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
	}
	return false;
}
bool pos(int x1,int y1,int x2,int y2){
	return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))<=S*S*V*V;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M>>S>>V;
	MO.resize(N);
	TU.resize(M);
	edge.resize(N);
	A.assign(N,-1);
	B.assign(M,-1);
	for(int i=0;i<N;++i){
		cin>>MO[i].first>>MO[i].second;
	}
	for(int i=0;i<M;++i){
		cin>>TU[i].first>>TU[i].second;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(pos(MO[i].first,MO[i].second,TU[j].first,TU[j].second)){
				edge[i].push_back(j);
			}
		}
	}
	int match=0;
	for(int i=0;i<N; i++){
        if(A[i] == -1){
            visited.assign(N,false);
            if(dfs(i)) {
            	match++;
            }
        }
    }
	cout<<N-match;
}