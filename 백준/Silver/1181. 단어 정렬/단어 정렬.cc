#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b){
	if(a.size()==b.size()){
		return a<b;
	}
	return a.size()<b.size();
}

int main(){
	int N;
	cin>>N;
	vector<string> words;
	for(int i=0;i<N;++i){
		string a;
		cin>>a;
		words.push_back(a);
	}
	sort(words.begin(),words.end(),compare);
	words.erase(unique(words.begin(),words.end()),words.end());
	for(auto e: words){
		cout<<e<<endl;
	}
}