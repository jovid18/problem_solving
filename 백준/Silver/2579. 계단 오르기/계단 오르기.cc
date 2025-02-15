#include <iostream>
#include <vector>
using namespace std;

struct ox{
	int o;
	int x;
};

int main(){
	int N;
	cin>>N;
	vector<int> stair;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		stair.push_back(a);
	}
	vector<ox> score(N);
	for(int i=0;i<N;++i){
		if(i==0){
			score[i].o=stair[i];
			score[i].x=stair[i];
		}else if(i==1){
			score[i].o=stair[i]+stair[i-1];
			score[i].x=stair[i];
		}else {
			score[i].o=stair[i]+score[i-1].x;
			score[i].x=stair[i]+max(score[i-2].o,score[i-2].x);
		}
	}
	cout<<max(score[N-1].o,score[N-1].x);
	
}