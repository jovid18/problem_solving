#include <iostream>
#include <cmath>
using ld=long double;
const ld pi = 3.14159265358979;
using namespace std;
ld X1,Y1,R1,X2,Y2,R2;
int main(){
	cin>>X1>>Y1>>R1>>X2>>Y2>>R2;
	ld D=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	cout<<fixed;
	cout.precision(3);
	if(D<=abs(R1-R2)){
		if(R1>=R2){
			cout<<R2*R2*pi;}
		else{
			cout<<R1*R1*pi;
		}
	}else if(R1+R2<=D){
		cout<<"0.000";
	}else{
		ld A1=acos((R1*R1+D*D-R2*R2)/(2*R1*D));
		ld A2=acos((R2*R2+D*D-R1*R1)/(2*R2*D));
		ld S1=(R1*R1*A1)-(R1*R1*sin(2*A1)/2);
		ld S2=(R2*R2*A2)-(R2*R2*sin(2*A2)/2);
		cout<<(S1+S2);
	}
}