#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;

bool primecheck(int num){
	if(num==1){
		return false;
	}
	for(int i=2;i<num;++i){
		if(num%i==0)
			return false;
	}
	return true;
}

int main(){
	int N;
	cin>>N;
	int count=0;
	for(int i=-0;i<N;++i){
		int a;
		cin>>a;
		if(primecheck(a)){
			count++;
		}
	}
	cout<<count;
}
