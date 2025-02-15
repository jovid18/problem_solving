#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int change(int a){
	double x=(sqrt(1+8*a)+1)/2;
	int y=x;
	return y;
}

int main(){
	
	int N,M;
	cin>>N>>M;
	int count=0;
	for(int i=N;i<=M;i++){
		count+=change(i-1);
	}
	cout<<count;


	return 0;
}