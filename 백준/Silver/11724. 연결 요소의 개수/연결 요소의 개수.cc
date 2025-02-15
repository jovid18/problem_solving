#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> check={false};
vector<vector<int>> vertex(1000);
queue<int> process;

void BFS(const vector<vector<int>> & vertex,queue<int> &process, vector<bool> &check ){
	int size=process.size();
	for(int i=0;i<size;++i){
		int first=process.front();
		for(int j=0;j<vertex[first].size();++j){
			if(!check[vertex[first][j]]){
				process.push(vertex[first][j]);
				check[vertex[first][j]]=true;
			}
		}
		process.pop();
	}
	
}

int main(){
	int N,M;
	cin>>N>>M;
	vertex.resize(N+1);
	check.resize(N+1);
	for(int j=0;j<M;++j){
		int a,b;
		cin>>a>>b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
	check[0]=true;
	int count=0;
	for(int i=1;i<=N;++i){
		if(!check[i]){
			count++;
			check[i]=true;
			process.push(i);
			while(!process.empty()){
				BFS(vertex, process,check);
			}
		}

	}
	cout<<count;
	
	
}