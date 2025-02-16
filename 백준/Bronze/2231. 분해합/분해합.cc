#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	
	vector<int> num(1000000,0);
	for(int i=1;i<=1000000;++i){
		num[i]=num[i]+i;
		string str=to_string(i);
		for(int j=0;j<str.length();j++){
			int a=str[j]-'0';
			num[i]+=a;
		}
	}
	int answer=0;
	for(auto iter=num.begin();iter!=num.end();iter++){
		if(*iter==N){
			answer=iter-num.begin();
			break;
		}
	}
	cout<<answer;
}