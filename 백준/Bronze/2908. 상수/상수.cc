#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string a;
	string b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int A=stoi(a);
	int B=stoi(b);
	if(A>B){
		cout<<A;
	}else{
		cout<<B;
	}
}