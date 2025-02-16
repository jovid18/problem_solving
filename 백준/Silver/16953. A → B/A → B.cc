#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> process;
int A,B;
bool check=true;
void BFS(queue<int> &process){
	int max=process.size();
	for(int i=0;i<max;++i){
		long long x=process.front();
		if(x*2<=1000000000){
			if(x*2==B){
				check=false;
			}
			process.push(x*2);
		}
		if(10*x+1<=1000000000){
			if(10*x+1==B){
				check=false;
			}
			process.push(10*x+1);
		}
		process.pop();
	}
}
int main(){
	cin>>A>>B;
	process.push(A);
	int count=0;
	while(!process.empty()&&check){
		BFS(process);
		count++;
	}
	if(!check){
		cout<<count+1;
	}else{
		cout<<-1;
	}
	
}