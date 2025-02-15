#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		int M;
		cin>>M;
		string s;
		cin>>s;
		for(int j=0;j<s.length();++j){
			for(int k=0;k<M;++k){
				cout<<s[j];
			}
		}
		cout<<endl;
	}
	
}