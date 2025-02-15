#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<long long> sol;

int main(){
	cin>>N;
	sol.resize(N);
	for(int i=0;i<N;++i){
		cin>>sol[i];
	}
	sort(sol.begin(),sol.end());
	auto start=sol.begin();
	long long sum=abs(sol[0]+sol[1]+sol[2]);
	vector<long long> answer(3);
	for(int i=0;i<3;++i){
		answer[i]=sol[i];
	}
	for(auto start=sol.begin();start!=sol.end()-2;start++){
		for(auto finish=start+2;finish!=sol.end();finish++){
			auto mid=lower_bound(start+1,finish,-1*(*start+*finish));
			if((mid-1)!=start){
				if(sum>abs(*start+*(mid-1)+*finish)){
				sum=abs(*start+*(mid-1)+*finish);
				answer[0]=*start;
				answer[1]=*(mid-1);
				answer[2]=*finish;
				}
			}
			if(mid==finish) continue;
			if(sum>abs(*start+*mid+*finish)){
				sum=abs(*start+*mid+*finish);
				answer[0]=*start;
				answer[1]=*mid;
				answer[2]=*finish;
			}
			mid++;
			if(mid==finish) continue;
			if(sum>abs(*start+*mid+*finish)){
				sum=abs(*start+*mid+*finish);
				answer[0]=*start;
				answer[1]=*mid;
				answer[2]=*finish;
			}
		}
	}
	for(auto e: answer){
		cout<<e<<" ";
	}
}