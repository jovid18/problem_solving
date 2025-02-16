#include <iostream>
#include <cmath>
#include <string>
using namespace std;
double d1,d2,x;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>d1>>d2>>x;
	if(d1<d2) swap(d1,d2);
	cout<<fixed;
	cout.precision(13);
	cout<<(100*d1*d2)/(d2*x+100*d1-d1*x);
}