#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[0]>s[i]){
			string copy=s;
			s[0]=copy[i];
			for(int j=1;j<=i;j++){
				s[j]=copy[j-1];
			}
		}else if(s[i]==s[0]){
			string copy=s;
			s[0]=copy[i];
			for(int j=1;j<=i;j++){
				s[j]=copy[j-1];
			}
			if(copy<s){
				s=copy;
			}
		}
	}
	cout<<s;
}