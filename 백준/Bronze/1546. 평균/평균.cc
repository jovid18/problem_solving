#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
double N,T,M=-1,X;
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>X;
		T+=X;
		M=max(M,X);
	}
	cout<<T/M/N*100;
}