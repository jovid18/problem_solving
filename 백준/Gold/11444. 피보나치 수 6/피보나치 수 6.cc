#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<unsigned long long, unsigned long long> m;

unsigned long long X=1000000007;
unsigned long long pibo(unsigned long long n){
	if(n==1){
		return 1;
	}else if(n==2){
		return 1;
	}else if(n%2==1){
		unsigned long long a=(n-1)/2;
		unsigned long long b=a+1;
		unsigned long long A;
		unsigned long long B;
		auto iter1=m.find(a);
		auto iter2=m.find(b);
		if (iter1!=m.end()){
			A=m[a];
		} else{
			A=pibo(a);
		}
		
		if (iter2!=m.end()){
			B=m[b];
		}else{
			B=pibo(b);
		}
		m[n]=(A*A+B*B)%X;
		return (A*A+B*B)%X;	  
	}else{
		unsigned long long a=n/2;
		unsigned long long b=a-1;
		unsigned long long A=pibo(a);
		unsigned long long B=pibo(b);
		auto iter1=m.find(a);
		auto iter2=m.find(b);
		if (iter1!=m.end()){
			A=m[a];
		}else{
			A=pibo(a);
		}
		if (iter2!=m.end()){
			B=m[b];
		}else{
			B=pibo(b);
		}
		m[n]=(A*A+2*A*B)%X;
		return (A*A+2*A*B)%X;
	}
}
int main(){
	unsigned long long n;
	cin>>n;
	cout<<pibo(n);
	
}