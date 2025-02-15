#include <iostream>

using namespace std;

int main(){
	int N;
	cin>>N;
	
	int a=0;
	int b=0;
	int c=-1;
	for(int i=N/5;i>=0;--i){
		if((N-5*i)%3==0){
			a=i;
			b=(N-5*i)/3;
			if(c==-1){
				c=a+b;
			}else{
				if(c>a+b){
					c=a+b;
				}	
			}
		}
	}
	cout<<c;
}