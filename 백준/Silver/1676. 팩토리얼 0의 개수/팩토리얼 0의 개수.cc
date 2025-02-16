#include <iostream>

using namespace std;

int main(){
	int five=0;
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		int a=0;
		int b=i;
		for(int j=1;j<=i;++j){
			if(b%5==0){
				a++;
				b/=5;
			}else{
				break;
			}
		}
		five+=a;
		
	}
	cout<<five;
}