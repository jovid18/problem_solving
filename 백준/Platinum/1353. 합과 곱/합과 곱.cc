#include <iostream>
#include <cmath>
using namespace std;
bool flag;
int main(){
	long double a,b;
	cin>>a>>b;
	if(a==b){
		cout<<1;
		return 0;
	}
	for(long double i=2;i<=a;++i){
		if((a/i-pow(b,1/i))>=0) {
			flag=true;
			cout<<i;
			break;
		}
	}
	if(!flag) cout<<-1;
}