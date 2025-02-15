#include <iostream>
using namespace std;
int main(){
	int x;
	cin>>x;
	if(x%4==0){
		if(x%100==0){
			if(x%400==0) cout<<1;
			else cout<<0;
		}else cout<<1;
	}else cout<<0;
}