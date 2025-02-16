#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	if(N==1){
		cout<<"*";
	}else
	{
for(int i=1;i<=N;++i){
		for(int j=0;j<i-1;++j){
			cout<<" ";
		}
		for(int j=0;j<=2*N-2*i;++j){
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=N-1;i>=1;--i){
		for(int j=0;j<i-1;++j){
			cout<<" ";
		}
		for(int j=0;j<=2*N-2*i;++j){
			cout<<"*";
		}
		if(i==1){
			break;
		}
		cout<<endl;
	}
	}

	
}