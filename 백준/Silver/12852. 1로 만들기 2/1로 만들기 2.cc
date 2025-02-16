#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
queue<int> process;
bool checked[1000001]={0};
int from[1000001]={0};
vector<int> answer;
void BFS(){
	while(!checked[N]){
		int first=process.front();
		process.pop();
		if(first+1<=1000000&&!checked[first+1]){
			checked[first+1]=true;
			process.push(first+1);
			from[first+1]=first;
		}
		if(first*2<=1000000&&!checked[first*2]){
			checked[first*2]=true;
			process.push(first*2);
			from[first*2]=first;
		}
		if(first*3<=1000000&&!checked[first*3]){
			checked[first*3]=true;
			process.push(first*3);
			from[first*3]=first;
		}
	}
}
int main(){
	cin>>N;
	checked[1]=true;
	process.push(1);
	BFS();
	answer.push_back(N);
	while(N!=1){
		N=from[N];
		answer.push_back(N);
	}
	cout<<answer.size()-1<<endl;
	for(auto e: answer){
		cout<<e<<" ";
	}
	
}