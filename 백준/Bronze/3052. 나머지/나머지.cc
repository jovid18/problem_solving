#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> num;
	for(int i=0;i<10;++i){
		int a;
		cin>>a;
		int b=a%42;
		num.push_back(b);
	}
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
	cout<<num.size();

}