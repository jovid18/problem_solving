#include <iostream>
using namespace std;
const double pi = 3.14159265358979;
int a,b,c;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(cin>>a>>b>>c){
		if(a==0) break;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		if(a+b<=c){
			cout<<"Invalid";
		}else if(a==b&&b==c){
			cout<<"Equilateral";
		}else if(a==b||b==c||c==a){
			cout<<"Isosceles";
		}else{
			cout<<"Scalene";
		}
		cout<<'\n';
	}
}