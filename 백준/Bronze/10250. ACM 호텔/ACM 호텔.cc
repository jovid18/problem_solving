#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int T;
int H,W,N;
int main(){
	cin>>T;
	while(T--){
		cin>>H>>W>>N;
		int a=(N-1)%H+1;
		int d=1+(N-1)/H;
		cout<<100*a+d<<'\n';
	}
}