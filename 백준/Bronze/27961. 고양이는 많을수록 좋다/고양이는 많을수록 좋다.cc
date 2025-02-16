#include <iostream>
#include <cmath>
using namespace std;
long long N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	if(N==0){
		cout<<0;
		return 0;
	}
	cout<<ceil(log2(N)+1);
}