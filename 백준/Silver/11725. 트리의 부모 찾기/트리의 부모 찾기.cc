#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> Graph(100001);
bool check[100001];
queue<int> process;
int parent[100001];
void BFS(vector<vector<int>> &Graph, queue<int> &process){
	int max=process.size();
	for(int i=0;i<max;++i){
		int first=process.front();
		for(auto e:Graph[first]){
			if(!check[e]){
				check[e]=true;
				process.push(e);
				parent[e]=first;
			}
		}
		process.pop();
	}
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=1;i<N;++i){
		int a,b;
		cin>>a>>b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	process.push(1);
	check[1]=true;
	while(!process.empty()){
		BFS(Graph,process);
	}
	for(int i=2;i<=N;++i){
		cout<<parent[i]<<'\n';
	}
}
