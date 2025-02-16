#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct session{
	unsigned long long start;
	unsigned long long finish;
	session(unsigned long long a, unsigned long long b){
		start=a;
		finish=b;
	}
};
bool compare(session a, session b){
	if(a.finish!=b.finish){
		return  a.finish<b.finish;
	}else{
		return a.start<b.start;
	}
}

int main(){
	vector<session> schedule;
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		unsigned long long a, b;
		cin>>a>>b;
		schedule.push_back(session(a,b));
	}
	sort(schedule.begin(),schedule.end(),compare);
	int count=1;
	unsigned long long deadline=schedule[0].finish;
	for(int i=1;i<schedule.size();++i){
		if(schedule[i].start>=deadline){
			count++;
			deadline=schedule[i].finish;
		}
	}
	cout<<count;
	
}