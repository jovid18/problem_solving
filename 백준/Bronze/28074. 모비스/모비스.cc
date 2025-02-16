#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;
vector<bool> C(26); 
int main(){
	cin>>s;
	for(int i=0;i<s.size();++i){
		C[s[i]-'A']=true;
	}
	string S="MOBIS";
	bool ok=true;
	for(int i=0;i<S.size();++i){
		if(!C[S[i]-'A']) ok=false;
	}
	if(ok){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}