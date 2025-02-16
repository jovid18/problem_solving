#include <iostream>
using namespace std;
int a,b;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(cin>>a>>b){
		if(!a&&!b) break;
		cout<<a+b<<'\n';
	}
}