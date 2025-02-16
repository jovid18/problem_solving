#include <iostream>
using namespace std;
int N,a,b,c;
int main(){
	cin>>N>>a>>b;
	while(N--){
		cin>>c;
		if(c*c<=a*a+b*b){
			cout<<"DA"<<'\n';
		}else{
			cout<<"NE"<<'\n';
		}
	}
}