#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	cout<<(N-1)*(N-1)<<'\n';
	for(int i=2;i<=N;++i){
		cout<<1<<" "<<i<<'\n';
	}
}