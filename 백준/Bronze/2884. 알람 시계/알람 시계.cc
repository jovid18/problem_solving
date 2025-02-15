#include <iostream>
#include <cmath>
using namespace std;
int H,M,T;
int main(){
	cin>>H>>M;
	T=60*H+M-45;
	if(T<0) T+=24*60;
	cout<<T/60<<" "<<T%60;
}