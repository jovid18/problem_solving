#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> pitch;
	for(int i=0;i<8;++i){
		int a;
		cin>>a;
		pitch.push_back(a);
	}
	vector<int> ascending=pitch;
	vector<int> descending=pitch;
	sort(ascending.begin(),ascending.end());
	sort(descending.begin(),descending.end(),greater<>());
	if(pitch==ascending){
		cout<<"ascending";
	}else if(pitch==descending){
		cout<<"descending";
	}else{
		cout<<"mixed";
	}
	
	
}