#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N;
vector<string> V;
map<string, int> m;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		string S;
		cin>>S;
		if(S.size()<6) continue;
		string s=S.substr(S.size()-6,6);
		if(s=="Cheese"){
			if(m.find(S)==m.end()){
				m.insert({S,0});
			}
		}
	}
	if(m.size()>=4){
		cout<<"yummy";
	}else{
		cout<<"sad";
	}
}