#include <iostream>
using namespace std;
unsigned long long A,B,C;

unsigned long long  power(unsigned long long a,unsigned long long b){
	if(b==1){
		return a%C;
	}
	if(b%2==0){
		unsigned long long c=power(a,b/2)%C;
		return c*c%C;
	}else{
		unsigned long long c=power(a,(b-1)/2)%C;
		return (c*c%C)*a%C;
	}
}

int main(){
	cin>>A>>B>>C;
	cout<<power(A,B);
}