#include <iostream>
#include <vector>
using namespace std;

int N,S;
vector<int> num;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>S;
	num.resize(N);
	for(int i=0;i<N;++i){
		cin>>num[i];
	}
	auto start=num.begin();
	auto end=num.begin();
	int sum=0;
	int interval=100001;
	
	while(true){
		if(start==num.end()) break;
		if(end==num.end()){
			if(sum>=S&&interval>end-start){
				interval=end-start;
			}
			sum-=*start;
			start++;
		}else if(sum<S){
			sum+=*end;
			end++;
		}else{
			if(interval>end-start){
				interval=end-start;
			}
			sum-=*start;
			start++;
		}
	}
	if(interval!=100001){
		cout<<interval;
	}else{
		cout<<0;
	}
	
}