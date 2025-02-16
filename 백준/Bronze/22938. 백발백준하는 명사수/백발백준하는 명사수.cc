#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
long long X1,Y1,r1,X2,Y2,r2;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>X1>>Y1>>r1>>X2>>Y2>>r2;
	long long d=(X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2);
	long long r=r1*r1+2*r1*r2+r2*r2;
	if(d<r){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}