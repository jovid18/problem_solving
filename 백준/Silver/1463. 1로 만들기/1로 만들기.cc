#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> check(1000001);
queue<int> process;

void BFS(queue<int> &process, vector<bool> &check){
	int max=process.size();
	for(int i=0;i<max;++i){
		int first=process.front();
		if((3*first<=1000001)&&!(check[3*first])){
			process.push(3*first);
			check[3*first]=true;
		}
		if((first+1<=1000001)&&!(check[first+1])){
			process.push(first+1);
			check[first+1]=true;
		}
		if((2*first<=1000001)&&!(check[2*first])){
			process.push(2*first);
			check[2*first]=true;
		}
		process.pop();
	}
}

int main(){
	int N;
	cin>>N;
	check[1]=true;
	process.push(1);
	int count=0;
	while(!check[N]){
		BFS(process, check);
		count++;
	}
	cout<<count;
	
}