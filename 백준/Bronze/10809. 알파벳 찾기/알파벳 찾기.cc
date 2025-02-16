#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int C[26];
string s;
int main(){
	memset(C,-1,sizeof(C));
	cin>>s;
	for(int i=0;i<s.size();++i){
		int x=s[i]-'a';
		if(C[x]==-1) C[x]=i;
	}
	for(int i=0;i<26;++i){
		cout<<C[i]<<" ";
	}
}