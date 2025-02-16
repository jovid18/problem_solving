#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
const int MAX=100000000;
vector<vector<int>> graph(100,vector<int> (100,MAX));

vector<vector<int>> FLOYD(vector<vector<int>> &graph){
	int n=graph.size();
	vector<vector<int>> copy=graph;
	for(int k=0;k<n;++k){
		vector<vector<int>> anothercopy=copy;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				anothercopy[i][j]=min(copy[i][j],copy[i][k]+copy[k][j]);
			}
		}
		copy=anothercopy;
	}
	return copy;
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	graph.resize(n);
	for(int i=0;i<m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		if(graph[a-1][b-1]>c){
			graph[a-1][b-1]=c;
		}
	}
	for(int i=0;i<n;++i){
		graph[i].resize(n);
		graph[i][i]=0;
	}
	vector<vector<int>> answer=FLOYD(graph);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(answer[i][j]==MAX){
				answer[i][j]=0;
			}
		}
	}
	for(auto e:answer){
		for(auto f:e){
			cout<<f<<" ";
		}
		cout<<endl;
	}
}