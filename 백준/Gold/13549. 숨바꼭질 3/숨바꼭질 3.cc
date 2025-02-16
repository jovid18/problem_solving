#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<int> times(1000001,1000000000);
vector<int> checked(1000001,false);
deque<int> process;

int main(){
	int s,f;
	cin>>s>>f;
	process.push_front(s);
	times[s]=0;
	while(true){
		if(checked[f]){
			break;
		}
		int first=process.front();
		checked[first]=true;
		process.pop_front();
		if(first+1<1000001&&!checked[first+1]){
			process.push_back(first+1);
			if(times[first+1]>times[first]+1){
				times[first+1]=times[first]+1;
			}
		}
		if(first-1>=0&&!checked[first-1]){
			process.push_back(first-1);
			if(times[first-1]>times[first]+1){
				times[first-1]=times[first]+1;
			}
		}
		if(2*first<1000001&&!checked[2*first]){
			process.push_front(2*first);
			if(times[2*first]>times[first]){
				times[2*first]=times[first];
			}
		}
	}
	cout<<times[f];
	
}