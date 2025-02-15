#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[101]={false};
vector<vector<int>> virus(101);
queue<int> process;

void BFS(const vector<vector<int>> & virus,queue<int> &process, bool check[101] ){
	int size=process.size();
	for(int i=0;i<size;++i){
		int first=process.front();
		for(int j=0;j<virus[first].size();++j){
			if(!check[virus[first][j]]){
				process.push(virus[first][j]);
				check[virus[first][j]]=true;
			}
		}
		process.pop();
	}
	
}

int main(){
	int N,M;
	cin>>N>>M;
	for(int j=0;j<M;++j){
		int a,b;
		cin>>a>>b;
		virus[a].push_back(b);
		virus[b].push_back(a);
	}
	
	process.push(1);
	check[1]=true;
	while(!process.empty()){
		BFS(virus, process,check);
	}
	int count=0;
	for(int i=2;i<=N;++i){
		if(check[i]==true){
			count++;
		}
	}
	cout<<count;
	
	
}