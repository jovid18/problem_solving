#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
const int MAX=100000000;
vector<vector<int>> graph(100,vector<int> (100,MAX));
vector<int> item;
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
	int n,m,r;
	cin>>n>>m>>r;
	item.resize(n);
	for(int i=0;i<n;++i){
		cin>>item[i];
	}
	graph.resize(n);
	for(int i=0;i<r;++i){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a-1][b-1]=c;
		graph[b-1][a-1]=c;
	}
	for(int i=0;i<n;++i){
		graph[i].resize(n);
		graph[i][i]=0;
	}
	vector<vector<int>> answer=FLOYD(graph);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(answer[i][j]==MAX){
				answer[i][j]=m+1;
			}
		}
	}
	for(int i=0;i<n;++i){
		answer[i][i]=0;
	}
	int maxitem=0;
	for(int i=0;i<n;++i){
		int nowitem=0;
		for(int j=0;j<n;++j){
			if(answer[i][j]<=m){
				nowitem+=item[j];
			}
		}
		maxitem=max(maxitem,nowitem);
	}
	cout<<maxitem;
}