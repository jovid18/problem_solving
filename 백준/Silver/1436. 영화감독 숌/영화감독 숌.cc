#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int x=666;
vector<int> V;
int main(){
	cin>>N;
	for(int i=666;i<=2666800;++i){
		string str=to_string(i);
		bool ok=false;
		for(int i=0;i+2<str.size();++i){
			if(str[i]=='6'&&str[i+1]=='6'&&str[i+2]=='6'){
				ok=true;
				break;
			}
		}
		if(ok) V.push_back(i);
	}
	cout<<V[N-1];
}