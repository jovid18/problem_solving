#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int x=1;
	for(int i=1;i<=a;++i){
		x*=i;
	}
	for(int i=1;i<=a-b;++i){
		x/=i;
	}
	for(int i=1;i<=b;++i){
		x/=i;
	}
	cout<<x;
	
	
}