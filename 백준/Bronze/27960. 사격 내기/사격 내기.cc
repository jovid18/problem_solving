#include <iostream>
using namespace std;
int A,B;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>A>>B;
	int ans=0;
	for(int i=0;i<10;++i){
		if(((A&(1<<i))&&(B&(1<<i)))||!((A&(1<<i))||(B&(1<<i)))) continue;
		ans|=(1<<i);
	}
	cout<<ans;
}