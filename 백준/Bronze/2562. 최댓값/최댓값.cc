#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> num;
	for(int i=0;i<9;++i){
		int a;
		cin>>a;
		num.push_back(a);
	}
	cout<<*max_element(num.begin(), num.end())<<endl;
	int max_index = max_element(num.begin(), num.end()) - num.begin()+1;
	cout<<max_index;
}