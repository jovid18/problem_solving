#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	int a,b,c;
	cin>>N>>a>>b>>c;
	a=min(a,N);
	b=min(b,N);
	c=min(c,N);
	int d=a+b+c;
	cout<<d;
	
	
}