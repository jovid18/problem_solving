#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
deque<int> dq;
vector<int> V;
int main(){
	cin>>N;
	if(N==0){
		cout<<0;
		return 0;
	}
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i];
	}
	sort(V.begin(),V.end());
	for(auto e: V){
		dq.push_back(e);
	}
	int x=round(0.15*(double)N);
	int y=x;
	while(y--){
		dq.pop_back();
		dq.pop_front();
	}
	int sum=0;
	while(dq.size()){
		sum+=dq.front();
		dq.pop_front();
	}
	cout<<round((double)sum/(double)(N-2*x));
}