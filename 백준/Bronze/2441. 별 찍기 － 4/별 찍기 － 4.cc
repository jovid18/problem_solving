#include <iostream>
using namespace std;

int main(){

	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=i-1;j++){
			cout<<" ";
		}
		for(int j=i;j<=a;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}