#include <iostream>
using namespace std;
int N,A,B,C;
int main(){
	cin>>N;
	int x;
	for(int i=0;i<N;++i){
		cin>>x;
		if(x==1){
			A++;
		}else if(x==-1){
			B++;
		}else{
			C++;
		}
	}
	if((N%2==0&&C>=N/2)||(N%2==1&&C>N/2)){
		cout<<"INVALID";
	}else{
		if(A>B){
			cout<<"APPROVED";
		}else{
			cout<<"REJECTED";
		}
	}
}