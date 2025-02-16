#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int n;
		cin>>n;
		pq.push(n);
	}
	int count=0;
	while(1){
		int first=pq.top();
		pq.pop();
		if(pq.empty()) break;
		int second=pq.top();
		pq.pop();
		count+=first+second;
		pq.push(first+second);
	}
	cout<<count;
}