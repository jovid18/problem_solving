#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct sol{
	int a;
	int b;
	sol(int c, int d){
		a=c;
		b=d;
	}
};
bool compare(sol x, sol y){
	return x.a<y.a;
}
int main(){
	int N;
	cin>>N;
	vector<sol> record;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		record.push_back(sol(a,b));
	}
	stable_sort(record.begin(),record.end(),compare);
	int count=0;
	int check=0;
	int who=0;
	for(auto e:record){
		if(who!=e.a){
			who=e.a;
			if(check==1){
				count++;
			}
			check=0;
		}
		if(check==0&&e.b==1){
			check=1;
		}else if(check==0&&e.b==0){
			check=0;
			count++;
		}else if(check==1&&e.b==1){
			check=1;
			count++;
		}else{
			check=0;
		}
	}
	if(check==1){
		count++;
	}
	cout<<count;
	
}