#include <iostream>
#include <string>
using namespace std;
string s;
int a,b,c;
int main(){
	cin>>s;
	a=s.length();
	for(int i=0;i<a;++i){
		if(s[i]==':') b++;
		if(s[i]=='_') c++;
	}
	cout<<a+b+5*c;
}