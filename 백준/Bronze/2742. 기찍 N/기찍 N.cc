#include <iostream>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int x;
	cin>>x;
	for(int i=x;i>=1;--i){
		cout<<i<<'\n';
	}
}