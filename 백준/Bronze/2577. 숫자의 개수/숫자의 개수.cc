#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int d=a*b*c;
	string result=to_string(d);
	vector<int> count(10,0);
	for(int i=0;i<result.size();++i){
		int num=result[i]-'0';
		count[num]++;
	}
	for(auto e:count){
		cout<<e<<endl;
	}

}