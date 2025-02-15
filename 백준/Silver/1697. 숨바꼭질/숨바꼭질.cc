#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> check(100001);
queue<int> process;

void BFS(queue<int> &process, vector<bool> &check){
	int max=process.size();
	for(int i=0;i<max;++i){
		int first=process.front();
		if((first-1>=0)&&!(check[first-1])){
			process.push(first-1);
			check[first-1]=true;
		}
		if((first+1<=100000)&&!(check[first+1])){
			process.push(first+1);
			check[first+1]=true;
		}
		if((2*first<=100000)&&!(check[2*first])){
			process.push(2*first);
			check[2*first]=true;
		}
		process.pop();
	}
}

int main(){
	int a,b;
	cin>>a>>b;
	check[a]=true;
	process.push(a);
	int count=0;
	while(!check[b]){
		BFS(process, check);
		count++;
	}
	cout<<count;
	
}