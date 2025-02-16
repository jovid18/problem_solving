#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<pair<int,int>>> Tree;
vector<int> Distance;
stack<int> Process;
int Find(int first, vector<int> &Distance){
	Distance[first]=0;
	Process.push(first);
	while(!Process.empty()){
		int t=Process.top();
		Process.pop();
		for(auto e: Tree[t]){
			if(Distance[e.first]==-1){
				Distance[e.first]=Distance[t]+e.second;
				Process.push(e.first);
			}
		}
	}
	return max_element(Distance.begin(),Distance.end())-Distance.begin();
}

int main(){
	cin>>N;
	Tree.resize(N+1);
	Distance.assign(N+1,-1);
	for(int i=1;i<=N-1;++i){
		int a,b,w;
		cin>>a>>b>>w;
		Tree[a].push_back({b,w});
		Tree[b].push_back({a,w});
	}
	int D1,D2;
	D1=Find(1,Distance);
	Distance.assign(N+1,-1);
	D2=Find(D1,Distance);
	cout<< *max_element(Distance.begin(),Distance.end());
}