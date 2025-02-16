#include <iostream>
using namespace std;
int main(){
	int ret=0,x;
	for(int i=0;i<5;++i){
		cin>>x;
		ret+=x*x;
	}
	cout<<ret%10;
}