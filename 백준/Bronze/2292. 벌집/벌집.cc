#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int n=0;
	while(N>=3*n*(n+1)+2){
		n++;
	}	
	cout<<n+1;
}