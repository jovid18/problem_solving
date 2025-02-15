#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
vector<int> B;
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

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M,K;
	cin>>N>>M>>K;
	edge.resize(2*N+1);
	A.assign(2*N+1,-1);
	B.assign(M+1,-1);
	
	for(int i=0;i<N;++i){
		int works;
		cin>>works;
		for(int j=0;j<works;++j){
			int work;
			cin>>work;
			edge[2*i].push_back(work);
			edge[2*i+1].push_back(work);
		}
	}
	int match1=0;
	visited.assign(2*N+1,false);
	for(int i=0;i<2*N; i+=2){
        if(A[i] == -1){
            visited.assign(2*N+1,false);
            if(dfs(i)) {
            	match1++;
            }
        }
    }
	int match2=0;
	visited.assign(2*N+1,false);
	for(int i=1;i<2*N; i+=2){
        if(A[i] == -1){
            visited.assign(2*N+1,false);
            if(dfs(i)){
            	match2++;
				if(match2==K) break;
            }
        }
    }
	cout<<match1+match2;
}