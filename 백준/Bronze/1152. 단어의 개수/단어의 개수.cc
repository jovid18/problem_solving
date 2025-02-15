#include <iostream>
#include <string>

using namespace std;
int main(){
	string a;
	getline(cin,a);
	int blankcheck=0;
	if(a[0]==' '){
			blankcheck++;
	}
	if(a[a.length()-1]==' '){
			blankcheck++;
		}
	int blankcheck2=0;
	for(int i=0;i<a.length();i++){
		if(a[i]==' '){
			blankcheck2++;
		}
	}
	cout<<1+blankcheck2-blankcheck;

}