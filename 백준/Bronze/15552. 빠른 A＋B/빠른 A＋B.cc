#include <iostream>
using namespace std;
int T;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	int a,b;
	while(T--&&cin>>a>>b){
		cout<<a+b<<'\n';
	}
}