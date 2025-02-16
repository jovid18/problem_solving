#include <iostream>

using namespace std;

int A,B,C,M;

int work=0;

int piro=0;

int main(){

	cin>>A>>B>>C>>M;	for(int i=0;i<24;++i){

		if(piro+A<=M){

			piro+=A;

			work+=B;

		}else{

			piro-=C;

			piro=max(0,piro);

		}

	}

	cout<<work;

}