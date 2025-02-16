#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int i;
	cin>>i;
	while(i!=0){
		string str=to_string(i);
		string str2=str;
		reverse(str.begin(),str.end());
		if(str==str2){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
		cin>>i;
	}
}