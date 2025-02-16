#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979;
double N,a,b,c,i=1;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	while(N--){
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		cout<<"Scenario #"<<i<<":\n";
		if(c*c==a*a+b*b){
			cout<<"yes"<<"\n\n";
		}else{
			cout<<"no"<<"\n\n";
		}
		++i;
	}
}